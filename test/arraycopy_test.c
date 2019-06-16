# include "function/arraycopy.c"

int main(void)
{
	int i, j;
	int	A[2][3] = {1, 2, 3, 4, 5, 6};
	int B[2][3] = {0};
	int C[2][3] = {6, 7, 8, 9, 0, 1};
	int D[2][3] = {0};
	int E[2][3] = {1, 3, 5, 7, 9, 0};
	int F[2][3] = {0};
	int count = 0;
	
	arraycopy(&B[0][0], &A[0][0], 2, 3);
	for(i = 0; i < 2; ++i)
		for(j = 0; j < 3; ++j)
			if(A[i][j] != B[i][j])
				++count;
	arraycopy(&D[0][0], &C[0][0], 2, 3);
	for(i = 0; i < 2; ++i)
		for(j = 0; j < 3; ++j)
			if(C[i][j] != D[i][j])
				++count;
	arraycopy(&F[0][0], &E[0][0], 2, 3);
	for(i = 0; i < 2; ++i)
		for(j = 0; j < 3; ++j)
			if(E[i][j] != F[i][j])
				++count;
				
	if(count == 0)
		printf("ÕýÈ·£¡\n");
	else
		printf("´íÎó£¡\n");
	
	return 0;
}
