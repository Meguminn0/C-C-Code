#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

struct Book
{
	char name[20];//����
	float price;//�۸�
	char PHome[20];//������
	char author[10];//����
};

int main(void)
{
	struct Book Book01 = {"�»��ֵ��10��", 100, "���������", "����"};
	struct Book* BookP = &Book01;//ȡ��ַ
	Book01.price = 95;//������ļ۸�
	strcpy(Book01.name, "�»��ֵ��11��");//��������
	//����BookP�õ�������Ƶ�
	printf("������%s\n", BookP->name);
	printf("�۸� % f\n", BookP->price);
	printf("�����磺%s\n", BookP->PHome);
	printf("���ߣ�%s\n", BookP->author);

	return 0;
}