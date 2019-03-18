#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include "cjgl.h"
struct stu *read(char a[])                                   /*函数：读取文件并将内容调入链表*/
{
	int n;
	stu *head;
	stu *p1, *p2;
	FILE *fp;
	a = strcat(a, ".txt");
	if ((fp = fopen(a, "r+")) == NULL)
	{
		printf("无法打开文件\n");
		exit(0);
	}
	n = 0;
	p1 = p2 = (stu *)malloc(sizeof(stu));
	head = NULL;
	fscanf(fp, "%s	%s	%s	%s	%f	%d", p1->name, p1->sex, p1->coll, p1->item, &p1->score, &p1->mark);
	printf("%s	%s	%s	%s	%.2f	%d\n", p1->name, p1->sex, p1->coll, p1->item, p1->score, p1->mark);
	while (p1->score >= 0 && p1->score <= 100)
	{
		n = n + 1;
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (stu *)malloc(sizeof(stu));
		fscanf(fp, "%s	%s	%s	%s	%f	%d", p1->name, p1->sex, p1->coll, p1->item, &p1->score, &p1->mark);
		/*if (p1->mark > 0)
			printf("%s	%s	%s	%s	%.2f	%d\n", p1->name, p1->sex, p1->coll, p1->item, p1->score, p1->mark);*/
	}
	p2->next = NULL;
	fclose(fp);
	return(head);
}
void change(stu *pt, char u[])                                /*函数：改变链表中的参数*/
{
	stu *p, *p1, *p2, *p3, *p4, *pt1, *pt2, *ch;
	char a[40], h[30], g[30][30] = { {0} }, o[30] = { 0 };
	int b, c, d = 1, D, e, f = 0, x, y, z, w, i = 0;
	pt1 = pt;
	pt2 = pt;
	do
	{
		printf("\n请输入要修改的学生姓名与项目（如：张三   跳高）：\n\n");
		scanf("%s %s", a, h);
		p = pt;
		p1 = pt;
		p2 = pt;
		p3 = pt;
		p4 = pt;
		x = 0;
		while (p != NULL)
		{
			w = 0;
			system("cls");
			if (strcmp(p->name, a) == 0 && strcmp(p->item, h) == 0)
			{
				system("cls");
				printf("\n %s	%s	%s	%s	%.2f	\n\n", p->name, p->sex, p->coll, p->item, p->score );
				printf("\n ************************************** \n *   1、修改姓名	2、修改性别   * \n *   3、修改学院	4、修改项目   * \n *   5、修改分数	0、退出程序   * \n ************************************** \n\n请选择想要修改的内容：\n\n");
				scanf("%d", &b);
				if (b == 0)
					exit(0);
				switch (b)
				{
				case 1:printf("\n 修改为："); scanf("%s", &p->name); p = p->next; break;
				case 2:printf("\n 修改为："); scanf("%s", &p->sex); p = p->next; break;
				case 3:printf("\n 修改为："); scanf("%s", &p->coll); p = p->next; break;
				case 4:printf("\n 修改为："); scanf("%s", &p->item); p = p->next; break;
				case 5:
				{
					printf("\n 修改为："); scanf("%f", &p->score);
					for (; i < 30 && strcmp(p->item, g[i]) != 0; i++)
					{
						if (strcmp(g[i], o) == 0)
							strcpy(g[i], p->item); strcpy(g[i + 1], "a"); break;
					}
					p = p->next;
					w++;
					break;
				}
				default:printf("无此项目数据，请重新输入\n");
				}
				x++;
			}
			else
				p = p->next;
		}


		if (x != 0)
		{
			do
			{
				y = 0;
				printf("\n ****************************************\n *   1、是	2、否	0、退出程序     * \n ****************************************\n是否继续修改：\n\n");
				scanf("%d", &c);
				if (c != 0 && c != 1 && c != 2)
					y++;
				if (y != 0)
					printf("\n请输入0、1、2继续程序\n");

			} while (c != 0 && c != 1 && c != 2);
			if (c == 0)
				exit(0);
		}
		else
		{
			do
			{
				y = 0;
				printf("\n ****************************************\n *   1、是	2、否	0、退出程序     * \n ****************************************\n该年中此学生未参加运动会，是否修改其他学生的内容：\n\n");
				scanf("%d", &c);
				if (c != 0 && c != 1 && c != 2)
					y++;
				if (y != 0)
					printf("\n请输入0、1、2继续程序\n");

			} while (c != 0 && c != 1 && c != 2);
			if (c == 0)
				exit(0);
		}
	} while (c == 1);
	system("cls");
	while (pt != NULL)
	{
		printf("%s	%s	%s	%s	%.2f	%d\n", pt->name, pt->sex, pt->coll, pt->item, pt->score, pt->mark);
		pt = pt->next;
	}
	do
	{
		y = 0;
		printf("\n ****************************************\n *   1、是	2、否	0、退出程序     * \n ****************************************\n是否确定保存并结束：\n\n");
		scanf("%d", &b);
		if (b != 0 && b != 1 && b != 2)
			y++;
		if (y != 0)
			printf("\n请输入0、1、2继续程序\n");

	} while (b != 0 && b != 1 && b != 2);
	FILE *fp;
	if ((fp = fopen(a, "w")) == NULL)
	{
		system("cls");
		printf("无法打开文件\n");
		exit(0);
	}
	if (b == 0)
		exit(0);
	if (b == 1)
	{
		wrifile(p4, u, g);
	}
	for (; pt != NULL; pt = ch)
	{
		ch = pt->next;
		free(pt);
	}
}
void alter(void)
{
	int y;
	stu *pt;
	char c[10];
	printf("\n  请输入所要修改的年份：\n\n");
	scanf("%s", c);
	pt = read(c);
	change(pt, c);
}