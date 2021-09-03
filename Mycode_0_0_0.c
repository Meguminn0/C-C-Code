 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int ADD(float a,float b)//加法函数
{
	float c = a + b;
	return c;
}

int SUB(float a,float b)//减法函数
{
	float c = a - b;
	return c;
}

int MUL(float a, float b)//乘法函数
{
	float c = a * b;
	return c;
}

int DIV(float a, float b)//除法函数
{
	float c = a / b;
	return c;
}

int main(void)
{
	float num1;
	float num2;
	float sum;
	float sub;
	float mul;
	float div;

	printf("请输入需要计算的两个数：");
	scanf_s("%f,%f",&num1,&num2);

	sum = ADD(num1,num2);
	printf("相加等于：%f\n",sum);

	sub = SUB(num1,num2);
	printf("相减等于：%f\n",sub);

	mul = MUL(num1,num2);
	printf("相乘等于：%f\n",mul);

	div = DIV(num1,num2);
	printf("相除等于：%f\n",div);

	return 0;
}