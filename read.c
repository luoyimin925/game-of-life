#include <stdio.h>
int  main()
{
	int a[3][3];
	int i,j;
	FILE* fp=fopen("xxx.txt","r"); //���ļ�
	if(fp==NULL)
	{
	    printf("���ļ�");
	    return -1;
	}
	for(i=0;i<3;i++)
	{
	    for(j=0;j<3;j++)
	    {
	        fscanf(fp,"%d",&a[i][j]);/*ÿ�ζ�ȡһ������fscanf���������ո���߻��н���*/
		}
	    fscanf(fp,"\n");
	}
	fclose(fp);
	for(i=0;i<3;i++)
	{
	    for(j=0;j<3;j++)
	    {
	        printf("%d ",a[i][j]);//���
	    }
	    printf("\n");
	}
    return 0;	
}
