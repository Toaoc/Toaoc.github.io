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
		default:printf("�����������������1��2��3��");
		}
	}
	return 0;

}
void display(void)
{
	printf("***********************�˶���ɼ�����ϵͳ*********************\n");
	printf("\t\t\t1.�ɼ���ѯ\n");
	printf("\t\t\t2.�ɼ�¼��\n");
	printf("\t\t\t3.�޸ĳɼ�\n");
	printf("\t\t\t4.�˳�\n");
	printf("����������1-4ִ�г���:\n");
}
