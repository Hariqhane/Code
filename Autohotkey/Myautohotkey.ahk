; 禁用CapsLock键
SetCapsLockState, AlwaysOff
; Restore folders in closing order (Ctrl+Win+T)
#Persistent
SetBatchLines, -1
global HistoryStack := []       ; 存储关闭历史记录
global RestoreIndex := 0        ; 当前恢复位置
MaxHistory := 5                ; 最大保存5条记录
shell := ComObjCreate("Shell.Application")
PrevWindows := []
SetTimer, MonitorExplorer, 800  ; 每0.8秒检测一次
MonitorExplorer:
    CurrWindows := []
    
    ; 获取当前所有资源管理器窗口路径
    try {
        for window in shell.Windows {
            if !InStr(window.FullName, "explorer.exe")
                continue
            try {
                if IsObject(window.Document) && IsObject(window.Document.Folder) {
                    path := window.Document.Folder.Self.Path
                    CurrWindows.Push(path)
                }
            } catch {
                continue
            }
        }
    } catch e {
        return
    }

    ; 检测关闭的窗口并更新历史
    closedPaths := []
    for idx, prevPath in PrevWindows {
        if !HasValue(CurrWindows, prevPath) {
            closedPaths.Push(prevPath)
        }
    }

    ; 将新关闭的路径按正确顺序压入栈顶
    if (closedPaths.Length() > 0) {
        ; 修复1: 按实际关闭顺序插入历史记录
        for each, path in closedPaths
            HistoryStack.InsertAt(1, path) ; 最后关闭的路径在栈顶

        RestoreIndex := 0  ; 重置恢复指针
        if (HistoryStack.Length() > MaxHistory)
            HistoryStack.Pop()
    }

    PrevWindows := CurrWindows.Clone()
return

^!t::
    global HistoryStack, RestoreIndex
    if (HistoryStack.Length() = 0) {
        ShowTooltip("No history records to restore.")
        return
    }

    RestoreIndex += 1
    if (RestoreIndex > HistoryStack.Length()) {
        ShowTooltip("All history records have been restored.")
        HistoryStack := []       ; 清空历史记录栈
        RestoreIndex := 0        ; 重置指针
        return
    }

    targetPath := HistoryStack[RestoreIndex]
    Run, explorer.exe "%targetPath%"
    ShowTooltip("Restore folder:`n" targetPath)
return

; 辅助函数保持不变
HasValue(arr, value) {
    for idx, val in arr {
        if (val = value)
            return true
    }
    return false
}

ShowTooltip(text) {
    TrayTip, Folder Restore, % text, 1
    SetTimer, HideTooltip, 1500
}

HideTooltip:
    TrayTip
return



; 鼠标中键模拟Alt+E快捷键
MButton::Send, !e

; 鼠标侧键模拟浏览器前进后退
XButton2::Send, !{Right}
XButton1::Send, !{Left}
; 滚轮上滚进行特定应用的滚动或其他动作
+WheelUp::
    SetTitleMatchMode, 2
    IfWinActive, Excel
    {
        ComObjActive("Excel.Application").ActiveWindow.SmallScroll(0,0,0,2)
    }
    else IfWinActive, PowerPoint
        ComObjActive("PowerPoint.Application").ActiveWindow.SmallScroll(0,0,0,3)
else IfWinActive, Word
    ComObjActive("Word.Application").ActiveWindow.SmallScroll(0,0,0,3)
else IfWinActive, Adobe Acrobat Professional -
{
    send,+{left}
}
else IfWinActive, - Mozilla Firefox
{
    Loop 4
        send,{left}
}
else
{
    ControlGetFocus, FocusedControl, A
    Loop 10
        SendMessage, 0x114, 0, 0, %FocusedControl%, A
}
return
; 滚轮下滚进行特定应用的滚动或其他动作
+WheelDown::
    SetTitleMatchMode, 2
    IfWinActive, Excel
    {
        ComObjActive("Excel.Application").ActiveWindow.SmallScroll(0,0,2,0)
    }
    else IfWinActive, PowerPoint
        ComObjActive("PowerPoint.Application").ActiveWindow.SmallScroll(0,0,3,0)
else IfWinActive, Word
    ComObjActive("Word.Application").ActiveWindow.SmallScroll(0,0,3,0)
else IfWinActive, Adobe Acrobat Professional -
{
    send,+{right}
}
else IfWinActive, - Mozilla Firefox
{
    Loop 4
        send,{right}
}
else
{
    ControlGetFocus, FocusedControl, A
    Loop 10
        SendMessage, 0x114, 1, 0, %FocusedControl%, A
}
return

; Ctrl+Shift+滚轮上滚在特定应用中进行更大幅度的滚动
^+WheelUp::
    SetTitleMatchMode, 2
    IfWinActive, Excel
    {
        ComObjActive("Excel.Application").ActiveWindow.SmallScroll(0,0,0,10)
    }
    else IfWinActive, PowerPoint
        ComObjActive("PowerPoint.Application").ActiveWindow.SmallScroll(0,0,0,10)
else IfWinActive, Word
    ComObjActive("Word.Application").ActiveWindow.SmallScroll(0,0,0,10)
else
{
    ControlGetFocus, FocusedControl, A
    Loop 500
        SendMessage, 0x114, 0, 0, %FocusedControl%, A
}
return

; Ctrl+Shift+滚轮下滚在特定应用中进行更大幅度的滚动
^+WheelDown::
    SetTitleMatchMode, 2
    IfWinActive, Excel
    {
        ComObjActive("Excel.Application").ActiveWindow.SmallScroll(0,0,10,0)
    }
    else IfWinActive, PowerPoint
        ComObjActive("PowerPoint.Application").ActiveWindow.SmallScroll(0,0,10,0)
else IfWinActive, Word
    ComObjActive("Word.Application").ActiveWindow.SmallScroll(0,0,10,0)
else
{
    ControlGetFocus, FocusedControl, A
    Loop 100
        SendMessage, 0x114, 1, 0, %FocusedControl%, A
}
return

; 使用CapsLock+c复制MathType公式
CapsLock & c::
    IfWinActive, MathType
    {
        Clipboard := ""
        Send, ^c
        ClipWait, 1
        if (StrLen(Clipboard) > 2)
        {
            Clipboard := SubStr(Clipboard, 2, StrLen(Clipboard) - 2)
        }
    }
return

; CapsLock+a快捷键选取当前行文本
CapsLock & a::
    Send {Home}
    Send +{End}
Return

; Ctrl+CapsLock+c复制文件路径到剪切板并显示为提示信息
#c::
    Clipboard =
    Send,^c
    ClipWait
    path = %Clipboard%
    Clipboard = %path%
    Tooltip,%path%
    Sleep,1000
    Tooltip
Return

; CapsLock+`切换当前窗口的置顶状态
CapsLock & `::
    WinGet, ExStyle, ExStyle, A
    if (ExStyle & 0x8) {
        WinSet, AlwaysOnTop, Off, A
    } else {
        WinSet, AlwaysOnTop, On, A
    }
return

; #L锁定计算机
#L::
    {
        Sleep 500
        SendMessage, 0x0112, 0xF170, 2,, Program Manager
        DllCall("LockWorkStation")
    }
return

; #Ctrl+Alt+Scroll, Home&end
^!WheelUp::
    Send, {Home}
return
^!WheelDown::
    Send, {End}
return

; Alt+; Home
!;::
    Send {Home}
return

;ALt+', End
!'::
    Send {End}
return
; ^: ctrl; !: alt;
^!;::
    Send ^{Home}
return
^!'::
    Send ^{End}
return

^+!;::
    Send ^+{Home}
return
^+!'::
    Send ^+{End}
return
+!;::
    Send +{Home}
return
+!'::
    Send +{End}
return

; Ctrl+; , 在行尾添加;
^;:: ; Ctrl+; hotkey
    Send, {End} ; Move cursor to the end of the line
    Send, `{;}` ; Correctly type ;
return
^+;::
    Send, {End} ; Move cursor to the end of the line
    Send, `{:}` ; Correctly type ;
return
; ; Ctrl+Shift+Q, 在稻壳阅读器中添加书签时自动删除后七个字符
; ^+Q::
;     Send, {F2}
;     Sleep, 50 ; 稍等一下以确保操作顺畅进行
;     Send, {Right}
;     Sleep, 50 ; 稍等一下以确保操作顺畅进行
;     Send, {Backspace 7}
; return

; ; 当按住Alt并向下滚动鼠标滚轮时，触发Win+T
; !WheelDown::
;     SendInput, {LWin Down}t{LWin Up}
; return

; ; 定义 Ctrl+Shift+W 删除快捷方式后缀
; ^+W::
;     Send, {F2}
;     Sleep, 50 ; 稍等一下以确保操作顺畅进行
;     Send, {Right}
;     Sleep, 50 ; 稍等一下以确保操作顺畅进行
;     Send, {Backspace 11}
; return

; 在Onenote中的上下角标快捷键, 用Ctrl+H和Ctrl和Ctrl+L
#IfWinActive ahk_class Framework::CFrame
    ^H:: ; 当按下Ctrl+H时
        Send, ^+{=} ; 模拟按下Ctrl+Shift+=
    return

    ^L:: ; 当按下Ctrl+L时
        Send, ^{=} ; 模拟按下Ctrl+=
    return

return
#IfWinActive
;!文字替换区
::\ts::typedef struct
::\dydy::≥
::\wqd::∞
::\bdy::≠
::\+-::±
::\xydy::≤
::\Q1::①
::\Q2::②
::\Q3::③
::\Q4::④
::\Q5::⑤
::\Q6::⑥
::\Q7::⑦
::\Q8::⑧
::\Q9::⑨
::\Q10::⑩
::\right::→
::\left::←
::\up::↑
::\down::↓
::\msa::.-     ;
::\msb::-...   ;
::\msc::-.-.   ;
::\msd::-.     ;
::\mse::.      ;
::\msf::..-.   ;
::\msg::--.    ;
::\msh::....   ;
::\msi::..     ;
::\msj::.---   ;
::\msk::-.-    ;
::\msl::.-..   ;
::\msm::--     ;
::\msn::-.     ;
::\mso::---    ;
::\msp::.--.   ;
::\msq::--.-   ;
::\msr::.-.    ;
::\mss::...    ;
::\mst::-      ;
::\msu::..-    ;
::\msv::...-   ;
::\msw::.--    ;
::\msx::-..-   ;
::\msy::-.--   ;
::\msz::--..   ;
::\ms0::-----  ;
::\ms1::.----  ;
::\ms2::..---  ;
::\ms3::...--  ;
::\ms4::....-  ;
::\ms5::.....  ;
::\ms6::-....  ;
::\ms7::--...  ;
::\ms8::---..  ;
::\ms9::----.  ;
::\v::∀ ;
::\E::∃ ;




