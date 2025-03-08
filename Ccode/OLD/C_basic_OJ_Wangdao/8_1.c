#include <stdio.h>
int main()
{
    struct Stu_info
    {
        char number[10];
        char name[10];
        char sex[2];
    } stu;
    scanf("%s", stu.number);
    scanf("%s", stu.name);
    scanf("%s", stu.sex);
    printf("%s %s %s", stu.number, stu.name, stu.sex);
    return 0;
}