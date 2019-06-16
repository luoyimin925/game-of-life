#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "function.c"

#define maxLine 15

int speedControl(char x)//控制图形刷新速度 
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

int main()
{
	int i,j,count,speed=500;
    char judge;
    int a[maxLine][maxLine]={0};
    int b[maxLine][maxLine]={0};

    readfile(&a[0][0], maxLine, maxLine);
    arraycopy(&b[0][0],&a[0][0], maxLine, maxLine);
    outputshape(&a[0][0], maxLine, maxLine);
    while(1)
    {
    	Sleep(speed);
        checklife(&a[0][0],&b[0][0], maxLine, maxLine);
        arraycopy(&a[0][0],&b[0][0], maxLine, maxLine);
        system("cls");
        outputshape(&b[0][0], maxLine, maxLine);
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
