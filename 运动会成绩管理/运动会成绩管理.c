#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include "cjgl.h"
void display(void);
int main(void)
{
	int a = 0;
	while (a != 4)
	{
		system("cls");
		display();
		scanf("%d", &a);
		switch (a)
		{
		case 1:search();
			break;
		case 2:enter();
			break;
		case 3:alter();
			break;
		case 4:exit(0);
			break;
		default:printf("输入错误！请输入数字1、2或3！");
		}
	}
	return 0;

}
void display(void)
{
	printf("***********************运动会成绩管理系统*********************\n");
	printf("\t\t\t1.成绩查询\n");
	printf("\t\t\t2.成绩录入\n");
	printf("\t\t\t3.修改成绩\n");
	printf("\t\t\t4.退出\n");
	printf("请输入数字1-4执行程序:\n");
}
