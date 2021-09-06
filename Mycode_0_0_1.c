 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//#define MAX 100//01_定义标识符常量
 
//#define MAX(X , Y) (X>Y?X:Y)//02_定义宏——带参数

//int MAX(int num1, int num2)//03_通常算法
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

	//04_初识指针
	int a = 5;
	char b = 's';
	float c = 3.14;

	printf("a = %d\n", a);//5
	printf("b = %c\n", b);//a
	printf("c = %f\n", c);//3.14
	printf("\n");
	
	int* cp = &a;//取地址
	char* xp = &b;
	float* op = &c;

	printf("cp :%p\n", cp);//查看地址
	printf("xp :%p\n", xp);
	printf("op :%p\n", op);
	printf("\n");

	printf("指针变量的大小\n");//指针变量的大小
	printf("%d\n", sizeof(cp));
	printf("%d\n", sizeof(xp));
	printf("%d\n", sizeof(op));
	printf("\n");

	*cp = 100;//解引用
	*xp = 'o';
	*op = 3.00;

	printf("a = %d\n", a);//100
	printf("b = %c\n", b);//b
	printf("c = %f\n", c);//3.00

	return 0;
}