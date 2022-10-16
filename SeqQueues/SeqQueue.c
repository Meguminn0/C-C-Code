#include<stdio.h>
#define MAXLEN 100
typedef int DataType;

//顺序队列的类型定义
typedef struct 
{
    DataType data[MAXLEN];
    //队头
    int front;
    //队尾
    int rear;
} SeqQueue;

//初始化队列操作
void InitQueue(SeqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}

//判断队列空操作
int EmptyQueue(SeqQueue *Q)
{
    if(Q->front == Q->rear)
    {
        return 1;
    }

    return 0;
}

//入队操作
int InQueue(SeqQueue *Q, DataType x)
{
    //判断是否是满队
    if(((Q->rear + 1) % MAXLEN) == Q->front)
    {
        printf("错误，该队为满队，不能继续入队!!\n");
        return 0;
    }
    
    //入队
    Q->rear = (Q->rear + 1) % MAXLEN;
    Q->data[Q->rear] = x;
    return 1;
}

//出队操作
int DeQueue(SeqQueue *Q, DataType *e)
{
    //判断是否是队空
    if(EmptyQueue(Q))
    {
        printf("错误，该队为空队，不能进行出队操作！！\n");
        return 0;
    }

    //出队
    Q->front = (Q->front + 1) % MAXLEN;
    *e = Q->data[Q->front];
    return 1;
}

//取队头元素
int GetFront(SeqQueue *Q, DataType *e)
{
    //判断是否是队空
    if(EmptyQueue(Q))
    {
        printf("错误，该队为空队，不能进行取队头元素操作！！\n");
        return 0;
    }

    //取队头元素
    *e = Q->data[(Q->front + 1) % MAXLEN];
    return 1;
}

//显示队列元素
void ShowQueue(SeqQueue *Q)
{
    int p = Q->front;
    //判断是否是队空
    if(EmptyQueue(Q))
    {
        printf("错误，该队为空队，不能进行显示操作！！\n");
        return;
    }

    //显示
    printf("从队头起，队列中的各元素为：");
    while(p != Q->rear)
    {
        printf("%5d", Q->data[++p]);
    }
    printf("\n");
}

//菜单
void Mune()
{
    printf("================菜单================\n");
	printf("        1. ————初始化队列            \n");
	printf("        2. ————入队操作              \n");
	printf("        3. ————出队操作              \n");
	printf("        4. ————求队头元素            \n");
	printf("        5. ————显示队中所有元素       \n");
	printf("        0. ————退出                  \n");
	printf("=====================================\n");
}

int main()
{
    SeqQueue newQueue;
    int choice;     //记录用户选择
    int loop = 1;   //控制循环
    while(loop)
    {
        //输出菜单
        Mune();
        printf("请输入你的选择(0~5):");
        fflush(stdin);
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:     //初始化队列
            {
                InitQueue(&newQueue);
                printf("队列初始化完成！！\n");
                break;
            }
            case 2:     //入队操作
            {
                int x;
                printf("请输入你要入队的数值:");
                fflush(stdin);
                scanf("%d", &x);
                if(InQueue(&newQueue, x))
                {
                    printf("入队成功~~~\n");
                }
                break;
            }
            case 3:     //出队操作
            {
                int outNum;
                if(DeQueue(&newQueue, &outNum))
                {
                    printf("出队成功！此次出队的元素值为：%d\n", outNum);
                }
                break;
            }
            case 4:     //求队头元素
            {
                int outNum;
                if(GetFront(&newQueue, &outNum))
                {
                    printf("队头元素值为：%d\n", outNum);
                }
                break;
            }
            case 5:     //显示队中所有元素
            {
                ShowQueue(&newQueue);
                break;
            }
            case 0:     //退出
            {
                loop = 0;
                printf("已退出！！\n");
                break;
            }
            default:
                printf("错误，请输入(0~5)的数:)");
            break;
        }
    }

    return 0;
}