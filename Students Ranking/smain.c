#include<stdio.h>

/*
    一个班上有 30名学生，每个学生的数据作为一个记录，
    每个记录包括学号、姓名、三门课程 的成绩和三门课程平均成绩。
    从键盘输入学生的学号、姓名及三门课的成绩。
    要求打印三门课程平均成绩最高分的学生记录；
*/

typedef struct
{
    char name[10];
    char id[20];
    float grades[3];    //成绩
    float aveGrades;    //平均成绩
} StudentsData;

//计算平均成绩
float Average(StudentsData *stu)
{
    float aver = (stu->grades[0] + stu->grades[1] + stu->grades[2]) / 
                (sizeof(stu->grades)/sizeof(stu->grades[0]));
    
    return aver;
}

//输出学生所有信息
void info(StudentsData *stu)
{
    printf("学生姓名: %s\n", stu->name);
    printf("学生学号: %s\n", stu->id);
    printf("学生三门课的成绩: %.2f, %.2f, %.2f\n", stu->grades[0], 
                            stu->grades[1], stu->grades[2]);
    printf("学生平均成绩: %.2f\n", stu->aveGrades);
}

int main()
{
    int highist = 0;    //平均成绩最高的学生的数组下标
    int stuNum; //学生个数
    printf("请输入学生个数：");
    fflush(stdin);
    scanf("%d", &stuNum);
    //用数组存放每个学生的信息
    StudentsData students[stuNum];

    //录入每个学生的三门课的成绩
    for(int i = 0; i < stuNum; i++)
    {
        printf("请输入第%d个学生的名字:", i+1);
        fflush(stdin);
        scanf("%s", &students[i].name);

        printf("请输入第%d个学生的学号:", i+1);
        fflush(stdin);
        scanf("%s", &students[i].id);

        printf("请输入第%d个学生的三门课的成绩，用空格隔开:", i+1);
        fflush(stdin);
        scanf("%f%f%f", &students[i].grades[0], 
                &students[i].grades[1], &students[i].grades[2]);
        
        printf("========================================\n");
    }

    //计算每个学生三门课程的平均成绩
    for(int i = 0; i < stuNum; i++)
    {
        students[i].aveGrades = Average(&students[i]);
    }

    //找到学生平均成绩最高的学生
    for(int i = 1; i < stuNum; i++)
    {
        if(students[highist].aveGrades < students[i].aveGrades)
        {
            highist = i;
        }
    }

    //输出与最高平均成绩相同的学生的信息
    printf("平均分最高的学生信息如下：\n");
    for(int i = 0; i < stuNum; i++)
    {
        if(students[i].aveGrades == students[highist].aveGrades)
        {
            info(&students[i]);
            printf("------------------------------------------\n");
        }
    }

    return 0;
}