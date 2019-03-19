#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include<conio.h>
#include "cjgl.h"
void display(void);
void display0(void);
int main(void)
{
	system("color F0");
	display0();
	int a = 0;
	while (a != 5)
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
		case 4:dele();
			break;
		case 5:exit(0);
			break;
		default:printf("输入错误！请输入数字1、2或3！");
		}
	}
	return 0;

}
void display0(void)
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
	while (_getch() != 13);
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
