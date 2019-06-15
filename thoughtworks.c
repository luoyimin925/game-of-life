#include <stdio.h>
#define maxLine 10
int readfile(int *pArr, int a, int b)
{
	int i,j;
	FILE* fp=fopen("xxx.txt","r"); //打开文件
	if(fp==NULL)
	{
	    printf("无文件");
	    return 0;
	}
	for(i=0;i<a;i++)
	{
	    for(j=0;j<b;j++)
	    {
	        fscanf(fp, "%d", pArr+b*i+j);//每次读取一个数，fscanf函数遇到空格或者换行结束
		}
	    fscanf(fp,"\n");
	}
	fclose(fp);
	
    return 0;
}

int main()
{
	int i,j,count;
    char judge;
    int a[maxLine][maxLine]={0};
    int b[maxLine][maxLine]={0};

    readfile(&a, maxLine, maxLine);
    
    /*a[3][3]=1;
    a[3][4]=1;
    a[3][5]=1;
    a[4][4]=1;
    a[5][4]=1;*/
    
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
            for (i=0;i<maxLine;i++)//非边界情况 
            {
                for (j=0;j<maxLine;j++)
                {
                    if ((i-1>=0)&&(j-1>=0)&&a[i-1][j-1]==1)count++;
                    if ((i-1>=0)&&a[i-1][j]==1)count++;
                    if ((i-1>=0)&&(j+1<maxLine)&&a[i-1][j+1]==1)count++;
                    if ((j-1>=0)&&a[i][j-1]==1)count++;
                    if ((j+1<maxLine)&&a[i][j+1]==1)count++;
                    if ((i+1<maxLine)&&(j-1>=0)&&a[i+1][j-1]==1)count++;
                    if ((i+1<maxLine)&&a[i+1][j]==1)count++;
                    if ((i+1<maxLine)&&(j+1<maxLine)&&a[i+1][j+1]==1)count++;
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
            /*
            if (a[0][1]==1) count++;//左上角的情况 
            if (a[1][0]==1) count++;
            if (a[1][1]==1) count++;
            if (count==2)
        	{
				b[0][0]=a[0][0]; 
        	}
        	else if (count==3)
        	{
            	b[0][0]=1;
        	}
        	else
        	{
            	b[0][0]=0;
        	}
        	count=0;
        	
        	if (a[0][maxLine-2]==1) count++;//右上角的情况 
            if (a[1][maxLine-2]==1) count++;
            if (a[1][maxLine-1]==1) count++;
            if (count==2)
        	{
				b[0][maxLine-1]=a[0][maxLine-1]; 
        	}
        	else if (count==3)
        	{
            	b[0][maxLine-1]=1;
        	}
        	else
        	{
            	b[0][maxLine-1]=0;
        	}
        	count=0;
        	
        	if (a[maxLine-2][0]==1) count++;//左下角的情况 
            if (a[maxLine-2][1]==1) count++;
            if (a[maxLine-1][1]==1) count++;
            if (count==2)
        	{
				b[maxLine-1][0]=a[maxLine-1][0]; 
        	}
        	else if (count==3)
        	{
            	b[maxLine-1][0]=1;
        	}
        	else
        	{
            	b[maxLine-1][0]=0;
        	}
        	count=0;
        	
        	if (a[maxLine-2][maxLine-2]==1) count++;//右下角的情况 
            if (a[maxLine-2][maxLine-1]==1) count++;
            if (a[maxLine-1][maxLine-2]==1) count++;
            if (count==2)
        	{
				b[maxLine-1][maxLine-1]=a[maxLine-1][maxLine-1];
        	}
        	else if (count==3)
        	{
            	b[maxLine-1][maxLine-1]=1;
        	}
        	else
        	{
            	b[maxLine-1][maxLine-1]=0;
        	}
        	count=0;*/
        	
            
            for (i=0;i<10;i++)
            {
                for (j=0;j<10;j++)
                {
                    a[i][j]=b[i][j];
                    if (b[i][j]==1) printf("*");
                    else printf("%d",b[i][j]);
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
