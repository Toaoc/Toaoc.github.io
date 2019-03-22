#include<io.h>
#include<stdio.h>
#include "cjgl.h"
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
void chainfree(struct stu *head)//用于释放链表
{
	stu *current;
	current = head;
	while (current != NULL)
	{
		head = current->next;
		free(current);
		current = head;

	}
}
void chaincheck(struct stu*head)
{
	stu *p;
	p = head;
	while (p != NULL)
	{
		printf("\n%s %s %s %s %.2f %d\n", p->name, p->sex, p->coll, p->item, p->score, p->mark);
		p = p->next;
	}
}
void goal(char *gname,struct stu*head)
{
	stu  *current, *prev;
	FILE *fp;
	char  gitem[30];
	int defen[10], i, mark, gmark;
	strcpy(gitem, "a");
	fp = fopen(gname, "a+");
	while (strcmp(gitem, head->item) != 0)
	{
		if (fscanf(fp,"%s", gitem) != 1)
		{
			printf("程序文件已遭到破坏！！");
			exit(1);
		}
		for (i = 0; i < 10; i++)
		{
			fscanf(fp, "%d", &defen[i]);
		}
		fscanf(fp, "%d", &gmark);
	}
	for (prev = current = head ,i = 0; current != NULL; prev = current, current = current->next)
	{
		if ((current->mark % 100) / 10 == 3 || (current->mark % 100) / 10 == 4)//团体项目的赋分
		{
			if ((current != head) && (strcmp(current->coll, prev->coll) == 0))
			{
				current->mark = prev->mark;
				continue;
			}
		}
		current->mark = ((current->mark) / 10) * 10 + defen[i];
		if (i < 9)
			i++;
	}
}
void color(short int x)//成绩查询时给前3名来的特效以及封面的五环颜色
{
	switch (x)
	{
	case 0: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 505);//五环颜色
		break;
	case 1: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 758);
		break;
	case 2: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 498);
		break;
	case 3: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 499);
		break;
	default: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		break;
	}
}
void correctfile(char *fname)//将文件名纠正的函数，录入、修改、删除时若不正常退出，会产生中间文件，该函数将其纠正
{
	char ofname[20];
	strcpy(ofname, fname);
	strcat(ofname, "c.txt");
	strcat(fname, ".txt");
	if (_access(ofname, 0) == 0)
	{
		remove(fname);
		rename(ofname, fname);
	}
}