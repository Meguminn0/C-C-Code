 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//#define MAX 100//01_�����ʶ������
 
//#define MAX(X , Y) (X>Y?X:Y)//02_����ꡪ��������

//int MAX(int num1, int num2)//03_ͨ���㷨
//{
//	if (num1 > num2)
//		return num1;
//	else
//		return num2;
//}

int main(void)
{
	//01
	//int a = MAX;
	//printf("a = %d\n",a);//a = 100

	//02
	//int a = 20;
	//int b = 60;
	//int max = MAX(a , b);
	//printf("max = %d",max);

	//03
	//int a = 20;
	//int b = 50;
	//int max = MAX(a, b);
	//printf("max = %d",max);

	//04_��ʶָ��
	int a = 5;
	char b = 's';
	float c = 3.14;

	printf("a = %d\n", a);//5
	printf("b = %c\n", b);//a
	printf("c = %f\n", c);//3.14
	printf("\n");
	
	int* cp = &a;//ȡ��ַ
	char* xp = &b;
	float* op = &c;

	printf("cp :%p\n", cp);//�鿴��ַ
	printf("xp :%p\n", xp);
	printf("op :%p\n", op);
	printf("\n");

	printf("ָ������Ĵ�С\n");//ָ������Ĵ�С
	printf("%d\n", sizeof(cp));
	printf("%d\n", sizeof(xp));
	printf("%d\n", sizeof(op));
	printf("\n");

	*cp = 100;//������
	*xp = 'o';
	*op = 3.00;

	printf("a = %d\n", a);//100
	printf("b = %c\n", b);//b
	printf("c = %f\n", c);//3.00

	return 0;
}