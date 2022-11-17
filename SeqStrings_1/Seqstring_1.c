#include <stdio.h>
#define MAXLEN 100

//定长顺序串的类型定义
typedef struct 
{
    char ch[MAXLEN];
    int len;
} SeqString;

//求串的长度操作
int StrLength(SeqString *str)
{
    int i = 0;
    while(str->ch[i] != '\0')
    {
        i++;
    }
    str->len = i;

    return i;
}

//串的建立操作
void CreateString(SeqString *str)
{
    fflush(stdin);
    gets(str->ch);      //输入一个字符串，并赋给str
    str->len = StrLength(str);
}

//求子串操作
//求串 str 从第 pos 位置开始，长度为 len 的子串
int SubString(SeqString *str, SeqString *Sub, int pos, int len)
{
    int i;
    //排除非法情况
    if(pos < 1 || pos > str->len || len < 1 || len > str->len - pos + 1)
    {
        Sub->len = 0;
        printf("参数错误！\n");
        return 0;
    }

    for(i = 0; i < len; i++)
    {
        Sub->ch[i] = str->ch[pos + i - 1];
    }

    //这里没有考虑Sub串的长度是否能存下len长的字符串
    Sub->ch[i] = '\0';
    Sub->len = len;

    return 1;
}

//删除子串的操作
//删除串 str 从指定位置 i 开始的连续 j 个字符
int StrDelete(SeqString *str, int i, int j)
{
    //判断非法情况
    if(i < 1 || i > str->len || j < 1 || j > str->len - i + 1)
    {
        printf("参数错误！！\n");
        return 0;
    }

    for(int k = i - 1; k < str->len; k++)
    {
        str->ch[k] = str->ch[k + j];
    }

    str->len = str->len - j;
    str->ch[str->len] = '\0';
    return 1;
}

//插入子串操作
//在串 str 的第 i 个位置开始插入子串 str1
int StrInsert(SeqString *str, SeqString *str1, int i)
{
    //判断插入字符串的位置是否出错
    if(i < 1 || i > str->len + 1)
    {
        printf("插入的位置错误！！\n");
        return 0;
    }

    //判断插入后的长度是否超过原串的长度,注意要留一位给字符串
    if(str->len + str1->len > MAXLEN - 1)
    {
        printf("插入失败！原串的长度不够，请减少子串的长度\n");
        return 0;
    }

    //进行插入操作
    //1 从第i位字符开始向后移动 str1->len 长度
    for(int j = str->len - 1; j >= i-1; j--)
    {
        str->ch[j + str1->len] = str->ch[j];
    }

    //2 将子串 str1 从第i 位开始依次插入
    for(int j = 0 ; j < str1->len; j++)
    {
        str->ch[i + j - 1] = str1->ch[j];
    }

    //3 更新str 的长度
    str->len = str->len + str1->len;
    //4 加上字符结束标志
    str->ch[str->len] = '\0';
    return 1;
}

//串的定位操作(暴力法)
//若串 str 中存在与串 str1 相同的子串，返回串 str1 在串 str 中第一次出现的位置
//若子串长度大于原串或没有找到，返回 -1
int StrIndex_BT(SeqString *str, SeqString *str1)
{
    int i , j;
    i = 0;  //指向主串str
    j = 0;  //指向子串str13

    //先排除非法情况
    if(str->len < str1->len)
    {
        return -1;
    }

    //开始查找
    while(i < str->len && j < str1->len)
    {
        if(str->ch[i] == str1->ch[j])
        {
            //当两个字符相同
            i++;
            j++;
        }
        else
        {
            //当两个字符不同
            i = i - j + 1;
            j = 0;
        }
    }

    //当存在子串
    if(j >= str1->len)
    {
        return i - j + 1;
    }

    return -1;
}

//求串的前缀表
//str————串
//prefix————前缀表
//n————串的长度
void Str_prefix(SeqString *str, int prefix[], int n)
{
    //一般第一个元素的前缀数为0
    prefix[0] = 0;
    //j指向串的元素下标
    int j = 1;
    //len指向j前一个元素对应的前缀表下标
    int len = 0;

    while(j < n)
    {
        //判断串中第j位的字符是否串中第len位的字符相等
        if(str->ch[j] == str->ch[len])
        {
            len++;
            prefix[j] = len;
            j++;
        }
        else
        {
            if(len > 0)
            {
                len = prefix[len  - 1];
            }
            else
            {
                prefix[j] = len;
                j++;
            }
        }
    }
}

//将前缀表整体向后移动一位，将第一位赋值-1
void Str_prefix_move(int prefix[], int n)
{
    for(int i = n - 1; i > 0; i--)
    {
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
}

//串的定位操作(KMP)
//若串 str 中存在与串 str1 相同的子串，返回串 str1 在串 str 中第一次出现的位置
//若子串长度大于原串或没有找到，返回 -1
int StrIndex_KMP(SeqString *str, SeqString *str1)
{
    //m 为主串的长度
    int m = str->len;
    //n 为子串的长度
    int n = str1->len;
    //i 指向主串str
    int i = 0;
    //j 指向子串str1
    int j = 0;
    int prefix[n];
    
    //子串的长度超过主串,不必比较
    if(m < n)
    {
        printf("子串的长度超过主串，主串中一定没有要找的子串!!\n");
        return -1;
    }

    //拿到前缀表
    Str_prefix(str1, prefix, n);
    Str_prefix_move(prefix, n);

    while(i < m)
    {
        //当j大于子串长度时，说明已经找到子串的主串中的位置，并返回第一个字符的位置(非下标)
        if(j >= n)
        {
            return i - j + 1;
        }

        //如果两个字符相同，则比较下一个
        if(str->ch[i] == str1->ch[j])
        {
            i++;
            j++;
        }
        else
        {
            j = prefix[j];
            //如果刚好是第一个字符不同，则j和i都加1(上一行中j 的值变为了-1)
            if(j == -1)
            {
                i++;
                j++;
            }
        }
    }

    //没有找到子串
    printf("主串中没有找到该子串!!\n");
    return -1;
}

//判断两个串相等操作
//相同返回0，不相同返回第一个不相同字符的差值，其他情况给出提示，并返回129，
int StrCompare(SeqString *str, SeqString *str1)
{
    int i = 0;

    //判断两个串的长度是否相同
    if(str->len != str1->len)
    {
        printf("两个串的长度不同!!两个串一定不相同！！\n");
        return 129;
    }
    
    //依次判断连个串中字符是否相等
    while(str->ch[i] != '\0')
    {
        if(str->ch[i] != str1->ch[i])
        {
            break;
        }

        i++;
    }

    //相同返回0
    if(i > str->len)
    {
        return 0;
    }

    //不相同返回第一个不相同字符的差值
    return str->ch[i] - str1->ch[i];
}

//两个串的连接操作
//连接成功返回1，失败返回0
int StrCat(SeqString *str, SeqString *str1)
{
    //排除连接后的长度大于等于MANLEN 的情况
    if(str->len + str1->len >= MAXLEN)
    {
        printf("连接后的长度大于或等于主串的最大长度！！\n");
        return 0;
    }

    //连接
    for(int i = 0; i <= str1->len; i++)
    {
        str->ch[str->len + i] = str1->ch[i];
    }
    //修改主串的长度
    str->len = str->len + str1->len;

    return 1;
}

//子串替换算法
//实现用子串 str_v 将主串 str 中的所有串 str_t 全部替换
void StrReplace(SeqString *str, SeqString *str_t, SeqString *str_v)
{
    int i;
    do
    {
        //找到主串中与串 str_t 相同起始位置
        i = StrIndex_BT(str, str_t);

        //若本次替换后的长度超过主串最大长度
        if(str->len - str_t->len + str_v->len > MAXLEN)
        {
            break;
        }

        //如果找到了就执行替换操作
        if(i != -1)
        {
            StrDelete(str, i, str_t->len);
            StrInsert(str, str_v, i);
            str->len = str->len - str_t->len + str_v->len;
        }
    } while(i != -1);
}

//串的清空
void StrClear(SeqString *str)
{
    //判断是否是空串
    if(str->len == 0)
    {
        printf("这是一个空串，不需要清空！！\n");
        return;
    }

    StrDelete(str, 1, str->len);
}

//串的复制
void StrCopy(SeqString *str, SeqString *str_t)
{
    ///判断str_t 的长度是否大于 str 的最大长度
    if(str->len < str_t->len)
    {
        printf("错误，子串的长度过长，主串无法存入！\n");
        return;
    }

    for(int i = 0; i < str_t->len; i++)
    {
        str->ch[i] = str_t->ch[i];
    }
    str->ch[str_t->len] = '\0';
}

//遍历串
void DisStr(SeqString *str)
{
    //判断是否是空串
    if(str->len == 0)
    {
        printf("这是一个空串！！\n");
        return;
    }

    //遍历
    for(int i = 0; i < str->len; i++)
    {
        printf("%c", str->ch[i]);
    }
    printf("\n");
}

//菜单
void Mune()
{
    printf("==========================================\n");
    printf("      1. 建立主串，并输出串的内容和长度      \n");
    printf("      2. 求主串中的子串                     \n");
    printf("      3. 删除主串中的子串                   \n");
    printf("      4. 向主串中插入子串                   \n");
    printf("      5. 查找主串中的子串(暴力)             \n");
    printf("      6. 查找主串中的子串(KMP)      	    \n");
    printf("      7. 比较两个串是否相同                 \n");
    printf("      8. 连接两个串                        \n");
    printf("      9. 用新的子串替换主串中的某个子串      \n");
    printf("      10. 查看主串内容                      \n");
    printf("      0. 退出                             \n");
    printf("==========================================\n");
} 

int main()
{
    SeqString string_1, string_2, string_tmp;
    SeqString *str, *str1, *stmp;
    str = &string_1;
    str1 = &string_2;
    stmp = &string_tmp;
    int loop = 1;
    int choice;
    while (loop)
    {
        Mune();
        printf("请输入你的选择(0~8)：");
        fflush(stdin);
        if(!scanf("%d", &choice))
        {
            printf("错误！！请输入数字！！\n");
            continue;
        }

        switch (choice)
        {
        case 1:     //建立主串，并输出串的内容和长度
        {
            printf("请输入主串的内容：");
            CreateString(str);
            printf("主串建立成功！\n");
            printf("主串的内容为：\n");
            DisStr(str);
            printf("主串的长度为：%d\n", str->len);
            break;
        }
        case 2:     //求主串中的子串
        {
            //必须初始化，因为在case2 结束后，pos和len变量值会和之前的一样
            int pos = 0;
            int len = 0;
            printf("请输入子串在主串中的起始位置:");
            fflush(stdin);
            if(!scanf("%d", &pos))
            {
                printf("输入错误！!\n");
                continue;
            }

            printf("请输入该子串的长度:");
            fflush(stdin);
            if(!scanf("%d", &len))
            {
                printf("输入错误！!\n");
                continue;
            }

            if(SubString(str, str1, pos, len))
            {
                DisStr(str1);
                printf("得到的子串长度为：%d\n", str1->len);
            }

            
            //操作结束，删除子串的内容
            StrClear(str1);
            break;
        }
        case 3:     //删除主串中的子串
        {
            int pos;
            int len;
            printf("请输入要删除子串的起始位置:");
            fflush(stdin);
            if(!scanf("%d", &pos))
            {
                printf("输入错误！!\n");
                continue;
            }

            printf("请输入要删除子串的长度:");
            fflush(stdin);
            if(!scanf("%d", &len))
            {
                printf("输入错误！!\n");
                continue;
            }

            if(StrDelete(str, pos, len))
            {
                printf("删除成功！！\n");
                printf("删除后的主串内容为：\n");
                DisStr(str);
                printf("删除后的主串的长度为：%d\n", str->len);
            }
            break;
        }
        case 4:     //向主串中插入子串
        {
            int i;
            printf("请输入你要插入的位置:");
            fflush(stdin);
            if(!scanf("%d", &i))
            {
                printf("输入错误！!\n");
                continue;
            }

            printf("请输入你要插入的子串的内容：");
            CreateString(str1);
            if(StrInsert(str, str1, i))
            {
                printf("子串插入成功！\n");
                printf("插入后子串的内容为：\n");
                DisStr(str);
                printf("插入后的主串的长度为：%d\n", str->len);
            }

            
            //操作结束，删除子串的内容
            StrClear(str1);
            break;
        }
        case 5:     //查找主串中的子串(暴力)
        {
            int i;  
            printf("请输入你要查找的子串内容：");
            CreateString(str1);
            i = StrIndex_BT(str, str1);
            if(i >= 0)
            {
                printf("主串中存在这个子串，且子串的位置在主串中的第%d个字符开始后%d位\n", i, str1->len);
            }
            else
            {
                printf("没有在主串中找到该字串！！\n");
            }

            //操作结束，删除子串的内容
            StrClear(str1);
            break;
        }
        case 6:     //查找主串中的子串(KMP)
        {
            int i;  
            printf("请输入你要查找的子串内容：");
            CreateString(str1);
            i = StrIndex_KMP(str, str1);
            if(i > 0)
            {
                printf("主串中存在这个子串，且子串的位置在主串中的第%d个字符开始后%d位\n", i, str1->len);
            }

            //操作结束，删除子串的内容
            StrClear(str1);
            break;
        }
        case 7:     //比较两个串的是否相同
        {
            int i;
            printf("请输入你要比较的子串：");
            CreateString(str1);
            i = StrCompare(str, str1);
            if(i != 129 && i != 0)
            {
                printf("两个字符串不相同，第一个不相同的字符的差值为：%d\n", i);   
            }
            else if(i != 129 && i == 0)
            {
                printf("两个字符串相同！！\n");
            }
            break;
        }
        case 8:     //连接两个串
        {
            printf("请输入要连接的子串内容：");
            CreateString(str1);
            if(StrCat(str, str1))
            {
                printf("连接成功！！\n");
                printf("连接后的主串内容为：\n");
                DisStr(str);
                printf("连接后的主串的长度为：%d\n", str->len);
            }

            //操作结束，删除子串的内容
            StrClear(str1);
            break;
        }
        case 9:     //用新的子串替换主串中的某个子串
        {
            printf("请输入被替换的串内容：");
            CreateString(stmp);
            printf("请输入用于替换的串的内容：");
            CreateString(str1);
            StrReplace(str,stmp,str1);
            printf("替换后的主串内容为：\n");
            DisStr(str);

            //删除子串和临时串的内容
            StrClear(str1);
            StrClear(stmp);
            break;
        }
        case 10:     //查看主串内容
        {
            printf("主串的内容为：\n");
            DisStr(str);
            break;
        }
        case 0:     //退出
        {
            loop = 0;
            printf("退出成功！\n");
            break;
        }
        default:
        {
            printf("错误！请重新输入！！\n");
            break;
        }
        }
    }
    
	return 0;
}