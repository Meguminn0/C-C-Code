 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int ADD(float a,float b)//�ӷ�����
{
	float c = a + b;
	return c;
}

int SUB(float a,float b)//��������
{
	float c = a - b;
	return c;
}

int MUL(float a, float b)//�˷�����
{
	float c = a * b;
	return c;
}

int DIV(float a, float b)//��������
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

	printf("��������Ҫ�������������");
	scanf_s("%f,%f",&num1,&num2);

	sum = ADD(num1,num2);
	printf("��ӵ��ڣ�%f\n",sum);

	sub = SUB(num1,num2);
	printf("������ڣ�%f\n",sub);

	mul = MUL(num1,num2);
	printf("��˵��ڣ�%f\n",mul);

	div = DIV(num1,num2);
	printf("������ڣ�%f\n",div);

	return 0;
}