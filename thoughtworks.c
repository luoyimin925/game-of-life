#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define maxLine 15
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

void out(int x[maxLine][maxLine])
{
	int i,j;
	for (i=0;i<maxLine;i++)
    {
        for (j=0;j<maxLine;j++)
        {
            if (x[i][j]==0) printf("○");
            else printf("■");
        }
        printf("\n");
    }
}

void copy(int x[maxLine][maxLine],int y[maxLine][maxLine])
{
	int i,j;
	for (i=0;i<maxLine;i++)
    {
        for (j=0;j<maxLine;j++)
        {
            x[i][j]=y[i][j];
        }
    }
}

int speedControl(char x)
{
	int speed=0;
	char mark;
	switch (x)
    {
    	case '1':speed=1000;break;
    	case '2':speed=750;break;
    	case '3':speed=500;break;
    	case '4':speed=250;break;
    	case '5':speed=50;break;
    	case 27:speed=0;break;
	}
	return speed;
}

void transform(int x[maxLine][maxLine],int y[maxLine][maxLine])
{
	int i,j,count=0;
	for (i=0;i<maxLine;i++)//非边界情况 
    {
        for (j=0;j<maxLine;j++)
        {
            if ((i-1>=0)&&(j-1>=0)&&x[i-1][j-1]==1)count++;
            if ((i-1>=0)&&x[i-1][j]==1)count++;
            if ((i-1>=0)&&(j+1<maxLine)&&x[i-1][j+1]==1)count++;
            if ((j-1>=0)&&x[i][j-1]==1)count++;
            if ((j+1<maxLine)&&x[i][j+1]==1)count++;
            if ((i+1<maxLine)&&(j-1>=0)&&x[i+1][j-1]==1)count++;
            if ((i+1<maxLine)&&x[i+1][j]==1)count++;
            if ((i+1<maxLine)&&(j+1<maxLine)&&x[i+1][j+1]==1)count++;
        	if (count==2)
        	{
				y[i][j]=x[i][j]; 
        	}
        	else if (count==3)
        	{
            	y[i][j]=1;
        	}
        	else
        	{
            	y[i][j]=0;
        	}
        	count=0;
        } 
    }
}

int main()
{
	int i,j,count,speed=500;
    char judge;
    int a[maxLine][maxLine]={0};
    int b[maxLine][maxLine]={0};

    readfile(&a, maxLine, maxLine);
    copy(b,a);
    out(a);
    while(1)
    {
    	Sleep(speed);
        transform(a,b);
        system("cls");
        copy(a,b);
        out(b);
        while (kbhit())
		{
	        char ch = getch();
	        if (ch==' ') system("pause");
	        else if (speedControl(ch)) speed=speedControl(ch);
			else return 0;
		}
    }
    return 0;
}
