#include <iostream>
#include <string>
using namespace std;

int BlockCount(string str, int n);

int main()
{
	cout<<"输入 n 个单词，单词之间用空格隔开"<<endl;
	string str;
	getline(cin,str);
	int x = 0;			//用x记录第i个字符开始后面的空格个数
	int i = 0;
	int num=0;			//记录单词个数
	int len=str.size();	//记录字符串的长度

	while(i<len)
	{
		x = BlockCount(str,i);	
		//直接跳过从第i位开始后有连续空格的地方
		if(x) i += x;

		//比较字符串中下标为 i 和下标为 i+1 的字符是否含有空格，
		//如果有，i跳到下标为i+2的字符,num加1，
		//没有则跳到下标为i+1的字符
		if(str[i] == ' ' && str[i+1] !=' ' || str[i] != ' ' && str[i+1] == ' ')
		{
			num++;
			i += 2;
		}
		else
		{
			i++;
		}
	}
	//当最后没有空格时，最后一个单词没有被记录，所以要主动加1
	if(str[len-1] != ' ')
		num++;

	cout<<"单词个数为："<<num<<endl;
	
	cin>>num;	//停止

	return 0;
}

//BlockCount 用于记录字符串str中第n个字符后面连续空格的个数
int BlockCount(string str, int n)	
{
	int count = 0;
    int max = str.size();
	while(str[n] == ' ' && n < max)
	{
		count++;
		n++;
	}

	return count;
}