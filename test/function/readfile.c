# include <stdio.h>

int readfile(int A[], int row, int col)//将文件内容存入数组 
{
	int i, j;
	
	FILE* fp = fopen("input.txt", "r"); //打开文件
	if(fp == NULL)
	{
		printf("无文件");
		return 1;
	}
	for(i = 0; i < row; ++i)
	{
		for(j = 0; j < col; ++j)
		{
			fscanf(fp, "%d", A + col*i + j);//每次读取一个数，fscanf函数遇到空格或者换行结束
		}
	fscanf(fp, "\n");
	}
	fclose(fp);
	
	return 0;
}
