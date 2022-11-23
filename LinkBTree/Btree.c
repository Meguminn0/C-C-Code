#include<stdio.h>
#include<stdlib.h>
typedef char DataType;

//树的链式存储结构类型定义
typedef struct tnode
{
	struct tnode *lchild;
	DataType data;
	struct tnode *rchild;
} BT;

//先(根)序遍历二叉树(DLR)
void PreOrder(BT *tree)
{
	if(tree == NULL)
	{
		return;
	}
	else
	{
		printf("%c ", tree->data);
		PreOrder(tree->lchild);
		PreOrder(tree->rchild);
	}
}

//中(根)序遍历二叉树(LDR)
void InOrder(BT *tree)
{
	if(tree == NULL)
	{
		return;
	}
	else
	{
		InOrder(tree->lchild);
		printf("%c ", tree->data);
		InOrder(tree->rchild);
	}
}

//后(根)序遍历二叉树(LRD)
void PostOrder(BT *tree)
{
	if(tree == NULL)
	{
		return;
	}
	else
	{
		PostOrder(tree->lchild);
		PostOrder(tree->rchild);
		printf("%c ", tree->data);
	}
}

//层次遍历
void LevelOrder(BT *tree)
{
	//一个指向树的队列
	BT *queue_T[100];
	int front, rear;
	//一个指向树的指针
	BT *p;

	//判断树是否为空
	if(tree == NULL)
	{
		return;
	}
	else
	{
		//树的根结点入队
		front = 0;
		rear = 1;
		queue_T[front] = tree;
	}

	while(front != rear)
	{
		p = queue_T[front];
		//访问指针p 所指树的根结点
		printf("%c ", p->data);
		front = (front + 1) % 100;

		if(p->lchild != NULL)
		{
			//左孩子进树
			queue_T[rear] = p->lchild;
			rear = (rear + 1) % 100;
		}

		if(p->rchild != NULL)
		{
			//右孩子进树
			queue_T[rear] = p->rchild;
			rear = (rear + 1) % 100;
		}
	}
}

//二叉树的建立(先序遍历)
BT *CreateTree_DLR()
{
	BT *tree;
	char ch;
	//一次输入一个字符，每次输入前要清空缓冲区
	fflush(stdin);
	scanf("%c", &ch);

	if(ch == '\n')
	{
		tree = NULL;
	}
	else
	{
		tree = (BT *)malloc(sizeof(BT));
		tree->data = ch;
		printf("请输入%c结点的左孩子结点(输入回车表示空)：", ch);
		tree->lchild = CreateTree_DLR();
		printf("请输入%c结点的右孩子结点(输入回车表示空)：", ch);
		tree->rchild = CreateTree_DLR();
	}

	return tree;
}

//用广义表表示法输出二叉树
//		  A
//	  /	 	 \
//	 B	 	  C
//	  \	 	 /
//	   D 	E
//(a,(b,( ,d),c,(e, )))
//a(b( ,d),c(e, ))
void ShowBT_Gen(BT *tree)
{
	if(tree != NULL)
	{
		printf("%c", tree->data);

		if(tree->lchild != NULL)
		{
			printf("(");
			ShowBT_Gen(tree->lchild);
			if(tree->rchild != NULL)
			{
				printf(",");
				ShowBT_Gen(tree->rchild);
			}
			else
			{
				printf(", ");
			}
			printf(")");
		}
		else if(tree->rchild != NULL)
		{
			printf("( ,");
			ShowBT_Gen(tree->rchild);
			printf(")");
		}
	}	
}

//统计二叉树的叶子结点数目
int LeafNum(BT *tree)
{
	int count = 0;
	int lch, rch;
	if(tree)
	{
		if(tree->lchild == NULL && tree->rchild == NULL)
		{
			return ++count;
		}
		lch = LeafNum(tree->lchild);
		rch = LeafNum(tree->rchild);
		count = count + rch + lch;
	}
	
	return count;
}

//求二叉树结点总数
int NodeNum(BT *tree)
{
	int count = 0;
	if(tree)
	{
		count++;
		count += NodeNum(tree->lchild);
		count += NodeNum(tree->rchild);
	}

	return count;
}

//求二叉树的深度
int DepTree(BT *tree)
{
	int ldep,rdep;
	if(tree == NULL)
	{
		return 0;
	}

	ldep = DepTree(tree->lchild);
	rdep = DepTree(tree->rchild);

	if(ldep > rdep)
	{
		return ldep + 1;
	}
	else
	{
		return rdep + 1;
	}
}

//菜单
void Memu()
{
	printf("===================================\n");
	printf("		1. 建立一个二叉树			 \n");
	printf("		2. 广义表表示法显示	   		 \n");
	printf("		3. 先序遍历			  		\n");
	printf("		4. 中序遍历			  		\n");
	printf("		5. 后序遍历			  		\n");
	printf("		6. 层次遍历			  		\n");
	printf("		7. 求叶子结点数目	  		 \n");
	printf("		8. 求二叉树总节点数目   	 \n");
	printf("		9. 求树深度				   	\n");
	printf("		0. 退出					   	\n");
	printf("===================================\n");
}

int main()
{
	BT *tree;
	int choice;
	int loop = 1;
	while (loop)
	{
		Memu();
		printf("请输入你的选择(0~9):");
		if(!scanf("%d", &choice))
		{
			printf("错误！！请输入(0~9)范围内的数字：\n");
			continue;
		}

		switch (choice)
		{
		case 1:		//建立一个二叉树
		{	
			printf("请输入树的根结点(输入回车表示空)：");
			tree = CreateTree_DLR();
			printf("二叉树建立成功！！\n");
			break;
		}
		case 2:		//广义表表示法显示
		{
			printf("二叉树用广义表可以表示为：");
			ShowBT_Gen(tree);
			printf("\n");
			break;
		}
		case 3:		//先序遍历
		{
			printf("二叉树先序遍历内容为：");
			PreOrder(tree);
			printf("\n");
			break;
		}
		case 4:		//中序遍历
		{
			printf("二叉树中序遍历内容为：");
			InOrder(tree);
			printf("\n");
			break;
		}
		case 5:		//后序遍历
		{
			printf("二叉树后续遍历内容为：");
			PostOrder(tree);
			printf("\n");
			break;
		}
		case 6:		//层次遍历
		{
			printf("二叉树层次遍历内容为：");
			LevelOrder(tree);
			printf("\n");
			break;
		}
		case 7:		//求叶子结点数目
		{
			printf("二叉树的叶子结点数目为：%d\n",LeafNum(tree));			
			break;
		}
		case 8:		//求二叉树总节点数目
		{
			printf("二叉树的总结点数目为：%d\n", NodeNum(tree));
			break;
		}
		case 9:		//求树深度
		{
			printf("二叉树的深度为：%d\n", DepTree(tree));
			break;
		}
		case 0:		//退出
		{
			loop = 0;
			printf("退出成功！！\n");
			break;
		}
		default:
		{
			break;
		}
		}
	}
	

	return 0;
}