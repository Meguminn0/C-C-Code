#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

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
	struct Book* BookP = &Book01;//取地址
	Book01.price = 95;//更改书的价格
	strcpy(Book01.name, "新华字典第11版");//更改书名
	//利用BookP得到书的名称等
	printf("书名：%s\n", BookP->name);
	printf("价格： % f\n", BookP->price);
	printf("出版社：%s\n", BookP->PHome);
	printf("作者：%s\n", BookP->author);

	return 0;
}