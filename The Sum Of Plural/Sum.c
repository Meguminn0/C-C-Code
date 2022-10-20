#include<stdio.h>

//利用add函数求两个复数2+3i和4+5i的和。（要求用结构体来定义复数）；
typedef struct
{
    float real; //实部
    float imag; //虚部
} Plural;

Plural Add(Plural *p1, Plural *p2)
{
    Plural sum;
    sum.real = p1->real + p2->real;
    sum.imag = p1->imag + p2->imag;
    return sum;
}

int main()
{
    Plural sum;
    Plural p1;
    Plural p2;
    printf("请输入第一个复数(格式：a+bi)：");
    fflush(stdin);
    scanf("%f+%fi", &p1.real, &p1.imag);

    printf("请输入第二个复数(格式：a+bi)：");
    fflush(stdin);
    scanf("%f+%fi", &p2.real, &p2.imag);

    sum = Add(&p1, &p2);
    printf("他们的和为：%.2f+%.2fi", sum.real, sum.imag);

    return 0;
}