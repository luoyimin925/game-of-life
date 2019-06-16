# include <stdio.h>

void outputshape(int A[], int row, int col)//Êä³öÍ¼ĞÎ 
{
	int i, j;
	
	for(i = 0; i < row; ++i)
	{
		for(j = 0; j < col; ++j)
		{
			if(*(A + col*i + j) == 0)
				printf("¡ğ");
			else
				printf("¡ö");
		}
		printf("\n");
	}
}
