# include <stdio.h>

void checklife(int A[], int B[], int row, int col)
{
	int i, j;
	int count = 0;
	
	for(i = 0; i < row; ++i)
	{
		for(j = 0; j < col; ++j)
		{
			if((i-1 >= 0) && (j-1 >= 0) && *(A + col*(i-1) + j-1) == 1)
				count++;
			if((i-1 >= 0) && *(A + col*(i-1) + j) == 1)
				count++;
			if((i-1 >= 0) && (j+1 < col) && *(A + col*(i-1) + j+1) == 1)
				count++;
			if((j-1 >= 0) && *(A + col*i + j-1) == 1)
				count++;
			if((j+1 < col) && *(A + col*i + j+1) == 1)
				count++;
			if((i+1 < row) && (j-1 >= 0) && *(A + col*(i+1) + j-1) == 1)
				count++;
			if((i+1 < row) && *(A + col*(i+1) + j) == 1)
				count++;
			if((i+1 < row) && (j+1 < col) && *(A + col*(i+1) + j+1) == 1)
				count++;
			if(count == 2)
			{
				*(B + col*i + j) = *(A + col*i + j); 
			}
			else if(count == 3)
			{
				*(B + col*i + j) = 1;
			}
			else
			{
				*(B + col*i + j) = 0;
			}
			count = 0;
		} 
	}
}
