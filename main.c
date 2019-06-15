#include <stdio.h>

int main()
{
    int i,j,count;
    char judge;
    int a[10][10]={0};
    int b[10][10]={0};

    a[1][1]=1;
    a[1][2]=1;
    a[1][3]=1;
    a[2][2]=1;
    a[3][2]=1;
    
    for (i=0;i<10;i++)
    {
        for (j=0;j<10;j++)
        {
            b[i][j]=a[i][j];
        }
    }

    for (i=0;i<10;i++)
    {
        for (j=0;j<10;j++)
        {
            if (a[i][j]==0) printf("0");
            else printf("*");
        }
        printf("\n");
    }

    while(1)
    {
        scanf("%c",&judge);
        if (judge=='y')
        {
            for (i=1;i<9;i++)
            {
                for (j=1;j<9;j++)
                {
                    if (a[i-1][j-1]==1)count++;
                    if (a[i-1][j]==1)count++;
                    if (a[i-1][j+1]==1)count++;
                    if (a[i][j-1]==1)count++;
                    if (a[i][j+1]==1)count++;
                    if (a[i+1][j-1]==1)count++;
                    if (a[i+1][j]==1)count++;
                    if (a[i+1][j+1]==1)count++;
                	if (count==2)
                	{
						b[i][j]=a[i][j]; 
                	}
                	else if (count==3)
                	{
                    	b[i][j]=1;
                	}
                	else
                	{
                    	b[i][j]=0;
                	}
                	count=0;
                } 
            }
            for (i=0;i<10;i++)
            {
                for (j=0;j<10;j++)
                {
                    a[i][j]=b[i][j];
                    printf("%d",b[i][j]);
                }
                printf("\n");
            }
        }
        else if (judge=='n')
        {
            break;
        }
    }
    return 0;
}
