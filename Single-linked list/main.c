#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

void CreateListH();
void CreateListL();
int LengthList();
void LocateElem();
void GetElem();
void ListInsert();
void ListDelete();
void DispList();
void Mune();

//单链表类型定义
typedef struct linknode
{
    //定义节点的数据域
    ElemType data;
    //定义节点的指针域
    struct linknode *next;
} LikList;

//单链表的初始化
LikList *InitList()
{
	LikList *head;
    //动态分配一个节点空间
	head = (LikList*)malloc(sizeof(LikList));
    //将指针域赋位空
	head->next = NULL;
    //返回头指针head
	return head;
}

//单链表的建立——头插法
void CreateListH(LikList *L, ElemType n)
{
    LikList *s;
    printf("请输入%d个整数:", n);
    fflush(stdin);
    for (int i = 0; i < n; i++)
    {
        //创建一个新的节点
        s = (LikList *)malloc(sizeof(LikList));
        //将新的数据存入新节点的数据域中
        scanf("%d", &s->data);
        //将头节点的指针域值赋给新创建节点的指针域
        s->next = L->next;
        //将新节点的地址存入头节点，即将新节点插入单链表L中3
        L->next = s;
    }
    printf("链表建立成功！！\n");
}

//单链表的建立——尾插法
void CreateListL(LikList *L, int n)
{
    LikList *last, *s;
    //用last指针标记单链表中最后的一个节点，这里的L是刚初始化的链表，只有一个头节点
    last = L;
    printf("请输入%d个整数：", n);
    fflush(stdin);
    for (int i = 0; i < n; i++)
    {
        //创建一个新的节点
        s = (LikList *)malloc(sizeof(LikList));
        //将新的数据存入新节点的数据域中
        scanf("%d", &s->data);
        //将新节点的指针域置空
        s->next = NULL;
        //使单链表中最后一个节点的指针域指向新的节点
        last->next = s;
        //将新节点作为单链表的最后的节点
        last = s;
    }
}

//求表长操作
int LengthList(LikList *L)
{
    //用于记录表长，因为带头单链表中头节点不算入链表长度，所以j的初始值为0
    int j = 0;
    //将指针p指向单链表第一个节点
    LikList *p = L->next;
    //当指针p不为空时
    while(p != NULL)
    {
        //将指针p指向当前指向节点(下一个节点)
        p = p->next;
        //将表长增1
        j++;
    }

    return j;
}

//按值查找
void LocateElem(LikList *L, ElemType x)
{
    //记录x值所在的位置(p指向的位置)，因为按值查找是从第一个节点开始查找的,所以j为1
    int j = 1;
    //因为头节点中不存储任何无关值，所以p指向第一个节点
    LikList *p = L->next;
    
    /*
        下面while中，p!=NULL 的作用是当查找到最后一个节点还没找到时，
        它的next 的值是NULL.这会导致下一次循环时出现溢出
    */
    while(p != NULL && p->data != x)     
    {
        //将指针p指向当前指向节点(下一个节点)的数据域
        p = p->next;
        //位置加1
        j++;
    }

    if(p != NULL)
    {
        printf("在表的第%d的位置找到了值为%d的节点！！\n", j, x);
    }else
    {
        printf("抱歉(T^T)!!，没有找到值为%d的节点\n", x);
    }
}

//按序号查找
void GetElem(LikList *L, int i)
{
    //记录当前查找的位序(p指向的位置)
    int j = 0;
    LikList *p = L;
    
    //排除非法的情况
    if(i < 1 || i > LengthList(L)) 
    {
        printf("抱歉(T^T),这个位置不在链表的长度范围内！！\n");
        return;
    }

    //一直向后查找，直到p指向第i个节点，或p为空
    while(p->next != NULL && j < i)
    {
        //将p指针指向下一个节点
        p = p->next;
        //位置增1
        j++;
    }

    //判断当前位置是否与要查找的位置相等
    if(i == j)
    {
        printf("在第%d位上找到值为%d的元素\n", i, p->data);
    }
}

//插入操作
void ListInsert(LikList *L, int i, ElemType x)
{
    //记录p指向的位置
    int j = 0;
    LikList *p, *s;
    p = L;

    //排除非法情况
    if(i < 1 || i > LengthList(L) + 1)
    {
        printf("插入的位置错误，不可以在%d位置插入\n", i);
        return;
    }

    //让p指向第i节点的前驱
    while(j < i - 1 && p->next != NULL)
    {
        p = p->next;
        j++;
    }

    //若p不为空，则将新节点插入到p指针后
    if(p != NULL)
    {
        s = (LikList*)malloc(sizeof(LikList));
        s->data = x;
        //执行第一步：将节点s的指针域指向节点p的下一个节点
        s->next = p->next;
        //执行第二步：将节点p的指针域改为指向新节点s
        p->next = s;
        printf("插入完成！！\n");
        printf("插入后的链表为：\n");
        DispList(L);
    }
    else
    {
        printf("插入失败！！\n");
    }
}

//删除操作
void ListDelete(LikList *L, int i, ElemType *e)
{
    //记录p指针指向的位置
    int j = 0;
    LikList *p, *s;
    p = L;

    //排除非法的情况
    if(i < 1 || i > LengthList(L))
    {
        printf("删除的位置错误，链表中没有第%d位\n", i);
        return;
    }

    //让p指向第i个节点的前驱
    while(p->next != NULL && j < i-1)
    {
        p = p->next;
        j++;
    }
    
    //判断p所指节点的前驱(第i个节点)是否为空
    if(p->next !=NULL)
    {
        //将指针s指向要删除的节点——第i个节点
        s = p->next;
        //将要删除的数据放入指针e中
        *e = s->data;
        //修改p->next 的值，使其指向s后的节点(被删节点的后驱)
        p->next = s->next;
        //释放指针 s 所指节点——使用free()函数
        free(s);
        printf("删除成功！！\n");
        printf("删除后的链表为：\n");
        DispList(L);
    }
    else
    {
        printf("删除失败！！\n");
    }
}

//单链表的遍历
void DispList(LikList *L)
{
    LikList *p = L->next;
    while(p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

//循环链表找直接前驱
LikList *prior(LikList *p)
{
    //q指向p的直接后继
    LikList *q = p->next;
    //从直接后继开始找，一直循环找，直到当q的后继为p时，这时的q就指向p的前驱
    //这里的p != NULL是为了防止误传入一个非循环单链表
    while(q->next != p || p != NULL)
    {
        p = p->next;
    }

    if(p == NULL)
    {
        printf("错误，你传入了一个非循环指针");
        return NULL;
    }

    return q;
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
	printf("	   6. 查看单链表的长度	  \n");
	printf("	   7. 查看单链表		 \n");
	printf("	   8. 退出			     \n");
	printf("=============================\n");
}

int main()
{
    LikList *head;	//创建链表
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
				//初始化顺序表
				head = InitList();
                //创建链表
                CreateListL(head,5);
				printf("创建成功！！\n");
				break;
			}
			case '2':
			{
				ElemType input;
				int id;
				printf("请输入你要插入的值:");
				fflush(stdin);
				scanf("%d", &input);
				printf("请输入你要插入的位置:");
				fflush(stdin);
				scanf("%d", &id);
				ListInsert(head, id, input);
				break;
			}
			case '3':
			{
				ElemType delElem;
				int input;
				printf("请输入你要删除的元素位序:");
				fflush(stdin);
				scanf("%d", &input);
				ListDelete(head, input, &delElem);
				break;
			}
			case '4':
			{
				ElemType elem;
				int input;
				printf("请输入你要查找元素的位序:");
				fflush(stdin);
				scanf("%d", &input);
				GetElem(head, input);
				break;
			}
			case '5':
			{
				ElemType elem;
				printf("请输入你要查找的值:");
				fflush(stdin);
				scanf("%d", &elem);
				LocateElem(head, elem);
				break;
			}
			case '6':
			{
				printf("这个顺序表的长度为：%d\n", LengthList(head));
				break;
			}
			case '7':
			{
				DispList(head);
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