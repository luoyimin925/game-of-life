# include <stdio.h>

void arraycopy(int A[], int B[], int row, int col)//将B数组的值赋给A
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
