# include <stdio.h>

void readfile(int A[], int row, int col)//���ļ����ݴ������� 
{
	int i, j;
	
	FILE* fp = fopen("input.txt", "r"); //���ļ�
	if(fp == NULL)
	{
		printf("���ļ�");
		return;
	}
	for(i = 0; i < row; ++i)
	{
		for(j = 0; j < col; ++j)
		{
			fscanf(fp, "%d", A + col*i + j);//ÿ�ζ�ȡһ������fscanf���������ո���߻��н���
		}
	fscanf(fp, "\n");
	}
	fclose(fp);
	
	return;
}
