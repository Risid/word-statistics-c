// WordStatistics.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SqList.h"
#pragma warning(disable:4996)
int main()
{
	SqList sq_list;
	InitList(&sq_list);

	FILE *fp;
	char str[33];

	memset(str, 0, sizeof(str));
	int hyphen = 0;
	int is_word = 0;
	char file_path[] = "D:/file.txt";
	int index = 0;
	char input_c;

	if ((fp = fopen(file_path, "r")) == NULL)
	{
		printf("%s打开失败！", file_path);
		return -1;
	}




	while (!feof(fp))
	{
		input_c = fgetc(fp);
		if ((input_c >= 'A' && input_c <= 'Z') || (input_c >= 'a' && input_c <= 'z'))
		{
			str[index] = input_c;
			index++;
			is_word = 1;
		}
		// 处理连字符
		else if (input_c == '-' && hyphen == 0 && is_word == 1)
		{
			hyphen = 1;
			str[index] = input_c;
			index++;
		}
		else 
		{
			if (index == 0)
			{
				continue;
			}
			int j = LocateElem(&sq_list, str);
			if (j != -1)
			{
				InsertList(&sq_list, j, str);
			}
			memset(str, 0, sizeof(str));
			index = 0;
		}

	}

	PrintList(&sq_list);

	return 0;
}

