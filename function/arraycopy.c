# include <stdio.h>

void arraycopy(int A[], int B[], int row, int col)//��y�����ֵ����x 
{
	int i, j;
	
	for(i = 0; i < row; ++i)
	{
		for(j = 0; j < col; ++j)
		{
			*(A + col*i + j) = *(B + col*i + j);
		}
	}
}
