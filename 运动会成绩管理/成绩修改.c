#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include "cjgl.h"
struct stu *read(char a[])                                   /*��������ȡ�ļ��������ݵ�������*/
{
	int n;
	stu *head;
	stu *p1, *p2;
	FILE *fp;
	char a1[20];
	strcpy(a1, a);
	strcat(a1, "c.txt");
	strcat(a, ".txt");
	rename(a1, a);
	if ((fp = fopen(a, "r+")) == NULL)
	{
		printf("�޷����ļ�\n");
		exit(0);
	}
	n = 0;
	p1 = p2 = (stu *)malloc(sizeof(stu));
	head = NULL;
	fscanf(fp, "%s	%s	%s	%s	%f	%d", p1->name, p1->sex, p1->coll, p1->item, &p1->score, &p1->mark);
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
void change(stu *pt, char u[])                                /*�������ı������еĲ���*/
{
	stu *p, *p1, *p2, *p3, *p4, *pt1, *pt2, *ch;
	char a[40], h[30], g[30][30] = { {0} }, o[30] = { 0 };
	int b, c, d = 1, D, e, f = 0, x, y, z, w, i = 0;
	pt1 = pt;
	pt2 = pt;
	do
	{
		printf("\n������Ҫ�޸ĵ�ѧ����������Ŀ���磺����   ���ߣ���\n\n");
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
				printf("\n ************************************** \n *   1���޸�����	2���޸�ѧԺ   * \n *   3���޸ĳɼ� 	 0���˳�����   * \n ************************************** \n\n��ѡ����Ҫ�޸ĵ����ݣ�\n\n");
				scanf("%d", &b);
				switch (b)
				{
				case 0:exit(0); break;
				case 1:printf("\n �޸�Ϊ��"); scanf("%s", &p->name); p = p->next; break;
				case 2:printf("\n �޸�Ϊ��"); scanf("%s", &p->coll); p = p->next; break;
				case 3:
				{
					printf("\n �޸�Ϊ��"); scanf("%f", &p->score);
					for (; i < 30 && strcmp(p->item, g[i]) != 0; i++)
					{
						if (strcmp(g[i], o) == 0)
							strcpy(g[i], p->item); strcpy(g[i + 1], "a"); break;
					}
					p = p->next;
					w++;
					break;
				}
				default:printf("�޴���Ŀ���ݣ�����������\n");
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
				printf("\n ****************************************\n *   1����	2����	0���˳�����     * \n ****************************************\n�Ƿ�����޸ģ�\n\n");
				//printf("\n%d\t%s\t%s\n", i, g[i], g[i + 1]);
				scanf("%d", &c);
				switch (c)
				{
				case 0:exit(0);
				case 1:break;
				case 2:break;
				default:printf("\n������0��1��2��������\n"); break;
				}
			} while (c != 0 && c != 1 && c != 2);
			if (c == 0)
				exit(0);
		}
		else
		{
			do
			{
				y = 0;
				printf("\n ****************************************\n *   1����	2����	0���˳�����     * \n ****************************************\n�����д�ѧ��δ�μ��˶��ᣬ�Ƿ��޸�����ѧ�������ݣ�\n\n");
				scanf("%d", &c);
				if (c != 0 && c != 1 && c != 2)
					y++;
				if (y != 0)
					printf("\n������0��1��2��������\n");

			} while (c != 0 && c != 1 && c != 2);
			if (c == 0)
				exit(0);
		}
	} while (c == 1);
	system("cls");
	/*while (pt != NULL)
	{
		printf("%s	%s	%s	%s	%.2f	%d\n", pt->name, pt->sex, pt->coll, pt->item, pt->score, pt->mark);
		pt = pt->next;
	}*/
	do
	{
		y = 0;
		printf("\n ****************************************\n *   1����	2����	0���˳�����     * \n ****************************************\n�Ƿ�ȷ�����沢������\n\n");
		scanf("%d", &b);
		if (b != 0 && b != 1 && b != 2)
			y++;
		if (y != 0)
			printf("\n������0��1��2��������\n");

	} while (b != 0 && b != 1 && b != 2);
	FILE *fp;
	
	if (b == 0)
		exit(0);
	if (strcmp(g[i+1],"a")==0)
	{
		wrifile(p4, u, g);
	}
	else
	{
		if ((fp = fopen(u, "w")) == NULL)
		{
			system("cls");
			printf("�޷����ļ�\n");
			exit(1);
		}
		for (p = p4; p != NULL; p = p->next)
		{
			fprintf(fp, " %s %s %s %s %.2f %d ", p->name, p->sex, p->coll, p->item, p->score, p->mark);
			//fprintf(stdout, " %s %s %s %s %.2f %d ", p->name, p->sex, p->coll, p->item, p->score, p->mark);
		}
		chainfree(p4);

	}
}
void alter(void)
{
	int y;
	stu *pt;
	char c[10];
	printf("\n  ��������Ҫ�޸ĵ���ݣ�\n\n");
	scanf("%s", c);
	pt = read(c);
	change(pt, c);
}