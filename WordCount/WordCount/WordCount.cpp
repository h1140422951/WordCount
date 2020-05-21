// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h> 
void CharCount()//统计字符个数
{
	FILE *f; // 文件指针
	errno_t err; //指示错误号码
	int Count1 = 0; //对文本中字符的个数计数
	char ch;//读取文件返回的字节
	if ((err = fopen_s(&f, "text.txt", "r")) != 0)
	{
		printf("text文件打开失败。");  //提示
	}

	ch = fgetc(f);//读取文本第一个字符
	while (ch != EOF)
	{
		Count1++; //读取一个字符增加1
		ch = fgetc(f); //读取下一个字符
	}
	printf("字符数为：%d个\n", Count1);//输出计数结果

	fclose(f); //关闭文件指针
}
void WordCount()//统计单词数
{
	FILE *f; // 文件指针
	errno_t err;//指示错误号码
	int Count2 = 0;//对文本中单词个数来计数
	int flag = 0; //用于判断单词之间的间隔
	char ch;//读取文件返回的字节
	if ((err = fopen_s(&f, "text.txt", "r")) != 0)
	{
		printf("text文件打开失败"); //提示
	}

	ch = fgetc(f);//读取文本第一个字符
	while (ch != EOF)
	{
		if (ch == ' ' || ch == ',' || ch == '.')// 单词之间的间隔
		{
			flag = 0;   //间隔处，判断flag=0
			ch = fgetc(f); //读取下一个字符
		}
		else
		{
			if (flag == 0) //间隔出现
			{
				Count2++; //记录单词个数计数+1
				flag = 1; //判断改变 flag = 1
			}
			ch = fgetc(f); //读取下一个字符
		}
	}
	printf("单词数为：%d个\n", Count2); //输出计数结果

	fclose(f);  //关闭文件指针
}
int main(int argc, char *argv[]) //main函数运行
{
	
	if ((strcmp(argv[1], "-c") == 0) && (strcmp(argv[2], "text.txt") == 0)) //统计字符个数
	{
		CharCount();
	}
	if ((strcmp(argv[1], "-w") == 0) && (strcmp(argv[2], "text.txt") == 0)) //统计单词个数
	{
		WordCount();
	}
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
