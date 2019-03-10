#include<stdio.h>
#include "cjgl.h"
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
	stu  *current;
	int a;
	for (current = head, a = 1; current != NULL; current = current->next, a++)
	{
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
	}
}
void goal5(struct stu*head)
{
	stu  *current;
	int a;
	for (current = head, a = 1; current != NULL; current = current->next, a++)
	{
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
	}
}