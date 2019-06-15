#include <stdio.h>
int  main()
{
	int a[3][3];
	int i,j;
	FILE* fp=fopen("xxx.txt","r"); //打开文件
	if(fp==NULL)
	{
	    printf("无文件");
	    return -1;
	}
	for(i=0;i<3;i++)
	{
	    for(j=0;j<3;j++)
	    {
	        fscanf(fp,"%d",&a[i][j]);/*每次读取一个数，fscanf函数遇到空格或者换行结束*/
		}
	    fscanf(fp,"\n");
	}
	fclose(fp);
	for(i=0;i<3;i++)
	{
	    for(j=0;j<3;j++)
	    {
	        printf("%d ",a[i][j]);//输出
	    }
	    printf("\n");
	}
    return 0;	
}
