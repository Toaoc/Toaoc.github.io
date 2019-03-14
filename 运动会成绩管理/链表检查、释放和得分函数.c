#include<stdio.h>
#include "cjgl.h"
#include<stdlib.h>
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