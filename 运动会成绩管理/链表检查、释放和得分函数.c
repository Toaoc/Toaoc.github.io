#include<stdio.h>
#include "cjgl.h"
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
void chainfree(struct stu *head)
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
		printf("\n%s%s%s%s%.2f%d\n", p->name, p->sex, p->coll, p->item, p->score, p->mark);
		p = p->next;
	}
}
void goal3(struct stu*head)
{
	stu  *current, *prev;
	int a;
	for (prev = current = head, a = 1; current != NULL; prev=current,current = current->next)
	{
		if ((current->mark % 100) / 10 == 3 || (current->mark % 100) / 10 == 4)
		{
			if ((current != head) && (strcmp(current->coll, prev->coll) == 0))
			{
				current->mark = prev->mark;
				continue;
			}
		}
		if (a == 1)
		{
			current->mark = ((current->mark) / 10) * 10 + 5;
		}
		else if (a == 2)
		{
			current->mark = ((current->mark) / 10) * 10 + 3;
		}
		else if (a == 3)
		{
			current->mark = ((current->mark) / 10) * 10 + 2;
		}
		else
		{
			current->mark = ((current->mark) / 10) * 10 + 0;
		}
		a++;
	}
}
void goal5(struct stu*head)
{
	stu  *current, *prev;
	int a;
	for (prev = current = head, a = 1; current != NULL; prev=current,current = current->next)
	{
		if ((current->mark % 100) / 10 == 3 || (current->mark % 100) / 10 == 4)
		{
			if ((current != head)&& (strcmp(current->coll, prev->coll) == 0))
			{
				current->mark = prev->mark;
				continue;
			}
		}
		if (a == 1)
		{
			current->mark = ((current->mark) / 10) * 10 + 7;
		}
		else if (a == 2)
		{
			current->mark = ((current->mark) / 10) * 10 + 5;
		}
		else if (a == 3)
		{
			current->mark = ((current->mark) / 10) * 10 + 3;
		}
		else if (a == 4)
		{
			current->mark = ((current->mark) / 10) * 10 + 2;
		}
		else if (a == 4)
		{
			current->mark = ((current->mark) / 10) * 10 + 1;
		}
		else
		{
			current->mark = ((current->mark) / 10) * 10 + 0;
		}
		a++;
		
	}
}
void color(short int x)
{        /*仅限改变0-15的颜色;如果在0-15那么实现他的颜色   因为如果超过15后面的改变的是文本背景色。*/
	switch (x)
	{
	case 0: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 505);
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