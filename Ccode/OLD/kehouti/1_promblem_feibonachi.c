#include <stdio.h>
#include <stdlib.h>
// #include <string.h> //string function
// 递归的斐波那契数列;
int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
//用非递归方法计算斐波那契数列
int fibonacci_non_recursive(int n)
{
    int a = 0, b = 1, c;
    if (n == 0)
    {
        return a;
    }
    if (n == 1)
    {
        return b;
    }
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
// 用数组/非递归地计算斐波那契数列
int fibonacci_array(int n)
{
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

// 主函数
int main()
{
    printf("The 10th Fibonacci number is: %d\n", fibonacci(10));
    printf("The 10th Fibonacci number is: %d\n", fibonacci_non_recursive(10));
    return 0;
}
