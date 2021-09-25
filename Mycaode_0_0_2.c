#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct Book
{
	char name[20];//书名
	float price;//价格
	char PHome[20];//出版社
	char author[10];//作者
};

int main(void)
{
	struct Book Book01 = {"新华字典第10版", 100, "人民出版社", "张三"};
	printf("书名：%s\n", Book01.name);
	printf("价格：%f\n", Book01.price);
	printf("出版社：%s\n", Book01.PHome);
	printf("作者：%s\n", Book01.author);

	return 0;
}