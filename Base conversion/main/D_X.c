#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

//链栈类型的定义
typedef struct stacknode
{
    ElemType data;
    struct stacknode *next;
}LikStack;

//链栈的初始化
LikStack *InitStack()
{
    LikStack *stk;
    stk = NULL;
    return stk;
}

//链栈判断栈空操作
int EmptyStack(LikStack *stk)
{
    if(stk == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//链栈的入栈操作
LikStack *Push(LikStack *stk, ElemType x)
{
    //创建新的结点p
    LikStack *p;
    p = (LikStack*)malloc(sizeof(LikStack));
    //将数据存入新节点的 data 域
    p->data = x;
    p->next = stk;
    //新节点成为栈顶
    stk = p;
    return stk;
}

//链栈的出栈操作
LikStack *Pop(LikStack *stk, ElemType *e)
{
    //判断是否是空栈
    if(EmptyStack(stk))
    {
        printf("错误，这是一个空栈\n");
        return NULL;
    }

    LikStack *p;
    p = stk;
    //将栈顶指针的数组域的值赋给e
    *e = stk->data;
    stk = stk->next;
    free(p);
    return stk;
}

//取栈顶元素操作
int GetTop(LikStack *stk, ElemType *e)
{
    //判断是否是空栈
    if(EmptyStack(stk))
    {
        printf("错误，这是一个空栈\n");
        return 0;
    }

    *e = stk->data;
    return 1;
}

//遍历所有元素
void DispStack(LikStack *stk)
{
    LikStack *p = stk;
    //判断是不是空栈
    if(EmptyStack(stk))
    {
        printf("错误，这是一个空栈\n");
        return;
    }

    while(p->next != NULL)
    {
        printf("|--\t%d\t--|\n", p->data);
        p = p->next;
    }
}

void D_X(LikStack *stk, ElemType num, int x)
{
    while(num)
    {
       stk = Push(stk, num%x);
       num /= x;
    }

    //如果是十六进制要将10~15的数转换为A~F;
    if(x = 16)
    {
        while(!EmptyStack(stk))
        {
            stk = Pop(stk, &num);
            switch(num)
            {
                case 10:
                    printf("%c", 'A');
                    break;
                case 11:
                    printf("%c", 'B');
                    break;
                case 12:
                    printf("%c", 'C');
                    break;
                case 13:
                    printf("%c", 'D');
                    break;
                case 14:
                    printf("%c", 'E');
                    break;
                case 15:
                    printf("%c", 'F');
                    break;
                default:
                    printf("%d",num);
                    break;
            }
        }
    }

    while(!EmptyStack(stk))
    {
        stk = Pop(stk, &num);
        printf("%d",num);
    }
}

int main()
{
    ElemType n = 221;
    LikStack *stk = InitStack();
    printf("%d转换为二进制为：", n);
    D_X(stk, n, 2);
    printf("\n");
    printf("%d转换为八进制为：", n);
    D_X(stk, n, 8);
    printf("\n");
    printf("%d转换为十六进制为：", n);
    D_X(stk, n, 16);

    system("pause");
    return 0;
}