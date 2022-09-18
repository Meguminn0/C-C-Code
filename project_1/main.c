#include<stdio.h>
#define MAXLEN 100
typedef int ElemType;


//顺序表的类型定义
typedef struct
{
    ElemType data[MAXLEN];
    long length;
} SqList;

//初始化顺序表
int InitList(SqList *L)
{
    L->length = 0;
}

//建立顺序表
void CreateList(SqList *L, int n)
{
    int i;
    printf("请输入%d个整数：",n);
	fflush(stdout);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &L->data[i]);
    }
    L->length = i;
}

//按位置查找
int GetElem(SqList *L, int i, ElemType *e)
{
	if(i > L->length || i < 1)
	{
		return 0;
	}else
	{
		*e = L->data[i - 1];	//顺序表第i个元素的下标时i-1
	}

	return 1;
}

//按值查找
int LocateElem(SqList *L, ElemType x)
{
	int i;
	for(i = 0; i < L->length; i++)
	{
		if(x == L->data[i])
		{
			return i + 1;	//返回这个元素的位置
		}
	}

	return 0;
}

//插入操作
int ListInsert(SqList *L, int i, ElemType x)
{
	//先判断顺序表是否已满
	if(L->length >= MAXLEN)
	{
		printf("顺序表的位置已满！！\n");
		return 0;
	}

	//判断插入的位置是否有效
	if(i < 1 || i > L->length + 1)
	{
		printf("插入的位置有误！！\n");
		return 0;
	}

	//如果插入的位置正好是length+1,就直接插入，不用移动
	if(i == L->length + 1)
	{
		L->data[i - 1] = x;
		L->length++;
		return 1;		
	}

	//将第i 位以后的数据元素向后移动一位
	for(int j = L->length - 1; j >= i - 1; j--)
	{
		L->data[j + 1] = L->data[j];
	}

	L->data[i - 1] = x;	//插入
	L->length++;	//表长加一
	return 1;
}

//删除操作
int ListDelete(SqList * L, int i, ElemType *e)
{
	//判断是否是空表
	if(L->length == 0)
	{
		printf("这是一个空表哦！！\n");
		return 0;
	}

	//判断删除的位置是否有效
	if(i < 0 || i > L->length)
	{
		printf("该位置上没有元素哦！！\n");
		return 0;
	}

	*e = L->data[i - 1];	//保存要删除的元素值
	
	//将第i 位以后的数据元素向前移动一位
	for(int j = i-1; j < L->length - 1; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;			//表长减1

	return 1;
}

//遍历线性表
void dispList(SqList *L)
{
	for(int i = 0; i < L->length; i++)
	{
		printf("%d\t", L->data[i]);
	}
	printf("\n");
}

//菜单
void Mune()
{
	printf("============菜单=============\n");
	printf("	   1. 建立顺序表		 \n");
	printf("	   2. 插入元素			 \n");
	printf("	   3. 删除元素			 \n");
	printf("	   4. 按位置查找元素	  \n");
	printf("	   5. 按值查找元素位置	  \n");
	printf("	   6. 查看顺序表的长度	  \n");
	printf("	   7. 查看顺序表		 \n");
	printf("	   8. 退出			     \n");
	printf("=============================\n");
}

int main()
{
    SqList newList;	//创建顺序表
	char loop = 1;
	while(loop)
	{
		Mune();
		char chs;
		fflush(stdin);
		scanf("%c", &chs);
		switch(chs)
		{
			case '1':
			{
				//创建顺序表
				CreateList(&newList,6);
				printf("创建成功！！\n");
				break;
			}
			case '2':
			{
				ElemType input;
				int id;
				printf("请输入你要插入的值?:");
				fflush(stdin);
				scanf("%d", &input);
				printf("请输入你要插入的位置:");
				fflush(stdin);
				scanf("%d", &id);
				if(ListInsert(&newList, id, input))
				{
					printf("插入成功！\n");
				}
				break;
			}
			case '3':
			{
				ElemType delElem;
				int input;
				printf("请输入你要删除的元素位序:");
				fflush(stdin);
				scanf("%d", &input);
				if(ListDelete(&newList, input, &delElem))
				{
					printf("成功在第%d的位置上删除元素%c，删除后的顺序表为\n", input, delElem);
					dispList(&newList);
				}
				break;
			}
			case '4':
			{
				ElemType elem;
				int input;
				printf("请输入你要查找元素的位序:");
				fflush(stdin);
				scanf("%d", &input);
				if(GetElem(&newList, input, &elem))
				{
					printf("查找成功！第%d位的元素值为:%d\n", input, elem);
				}
				break;
			}
			case '5':
			{
				ElemType elem;
				int id;
				printf("请输入你要查找的值?:");
				fflush(stdin);
				scanf("%d", &elem);
				id = LocateElem(&newList, elem);
				if(id)
				{
					printf("查找成功！这个值位于顺序表的第%d位\n",id);
				}else
				{
					printf("查找失败?,顺序表中没有这个值！！\n");
				}
				break;
			}
			case '6':
			{
				printf("这个顺序表的长度为：%d\n", newList.length);
				break;
			}
			case '7':
			{
				dispList(&newList);
				printf("遍历完成！！\n");
				break;
			}
			case '8':
			{
				loop = 0;
				printf("成功退出！！\n");
				break;
			}
			default:
			{
				printf("输入错误！请重新输入\n");
				break;
			}
		}
	}

    return 0;
}