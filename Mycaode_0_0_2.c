#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

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
	printf("������%s\n", Book01.name);
	printf("�۸�%f\n", Book01.price);
	printf("�����磺%s\n", Book01.PHome);
	printf("���ߣ�%s\n", Book01.author);

	return 0;
}