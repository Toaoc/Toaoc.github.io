#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include<conio.h>
#include "cjgl.h"
void display(void);//主菜单显示
void display0(void);//封面显示
int main(void)
{
	system("color F0");
	display0();
	int a = 0;
	char ch;
	while (a != 5)
	{
		system("cls");
		display();
		while (scanf("%d", &a) != 1)
		{
			while ((ch = getchar() != '\n') && ch != EOF);
			printf("输入错误，请重新输入：\n");
		}
		switch (a)
		{
		case 1:search();
			break;
		case 2:enter();
			break;
		case 3:alter();
			break;
		case 4:dele();
			break;
		case 5:exit(0);
			break;
		default:printf("输入错误！请输入数字1-5！");
		}
	}
	return 0;

}
void display0(void)//封面
{
	color(0);
	printf("			        *  *                  *  *                  *  *         \n");
	printf("			   *            *        *            *        *            *    \n");
	printf("			 *                *    *                *    *                *    \n");
	printf("			*                  *  *                  *  *                  *   \n");
	printf("			*                  *  *                  *  *                  *\n");
	printf("			 *            *   *    *   *        *   *    *   *             *  \n");
	printf("			   *        *   *        *   *    *   *        *   *         *   \n");
	printf("			        *  *                  *  *                  *  *       \n");
	printf("			           *                  *  *                  *          \n");
	printf("			            *                *    *                *             \n");
	printf("			              *            *        *            *              \n");
	printf("			                   *  *                  *  *                               \n\n\n");
	color(4);
	printf("					******************************\n					*                            *\n					* 欢迎使用运动会成绩管理系统 * \n					*                            *\n					******************************");
	printf("\n\n						--→Enter进入←--");
	while (_getch() != 13);//用于判断输入的是否是enter键
}
void display(void)
{
	system("cls");
	printf("\n***********************运动会成绩管理系统*********************\n\n");
	printf("\t\t\t|1.成绩查询\n");
	printf("\t\t\t|2.成绩录入\n");
	printf("\t\t\t|3.修改成绩\n");
	printf("\t\t\t|4.删除成绩\n");
	printf("\t\t\t|5.退出\n");
	printf("\n请输入数字1-5执行程序:\n");
}
