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
		default:printf("�����������������1��2��3��");
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
	printf("					******************************\n					*                            *\n					* ��ӭʹ���˶���ɼ�����ϵͳ * \n					*                            *\n					******************************");
	printf("\n\n						--��Enter�����--");
	while (_getch() != 13);
}
void display(void)
{
	system("cls");
	printf("\n***********************�˶���ɼ�����ϵͳ*********************\n\n");
	printf("\t\t\t|1.�ɼ���ѯ\n");
	printf("\t\t\t|2.�ɼ�¼��\n");
	printf("\t\t\t|3.�޸ĳɼ�\n");
	printf("\t\t\t|4.ɾ���ɼ�\n");
	printf("\t\t\t|5.�˳�\n");
	printf("\n����������1-5ִ�г���:\n");
}
