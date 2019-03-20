#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "cjgl.h"
char *s_gets(char *st, int n)
{
	char *re, *find;
	char c;
	if (n % 10 == 0)
		while ((c = getchar() != '\n') && c != EOF);
	re = fgets(st, n, stdin);
	if (re)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
	}
	return re;
}
struct stu *maxsort(stu *head)//该函数是从1个逐渐拉到多个的排法
{
	stu *pfirst = NULL;
	stu *ptail = NULL;
	stu *pmaxBefore = NULL;
	stu *pmax = NULL;
	stu *p = NULL;
	while (head != NULL)
	{
		for (p = head, pmax = head; p->next != NULL; p = p->next)
		{
			if (p->next->score > pmax->score)
			{
				pmaxBefore = p;
				pmax = p->next;//找出最大的链节
			}
		}

		if (pfirst == NULL)
		{
			pfirst = pmax;//将最大链节赋给pfirst指针
			ptail = pmax;
		}
		else
		{
			ptail->next = pmax;
			ptail = pmax;//逐渐拉开排序
		}
		//printf("\t%s\t%.2f\n", ptail->name, ptail->score);
		if (pmax == head)
		{
			head = head->next;//若最大的链节为head，则将head去掉
		}
		else
		{
			pmaxBefore->next = pmax->next;//去掉最大的链节后再进行排序，类似冒泡
		}
	}
	if (pfirst != NULL)
	{
		ptail->next = NULL;
	}
	head = pfirst;
	return head;
}
struct stu *minsort(stu *head)//该函数是从1个逐渐拉到多个的排法
{
	stu *pfirst = NULL;
	stu *ptail = NULL;
	stu *pminBefore = NULL;
	stu *pmin = NULL;
	stu *p = NULL;
	while (head != NULL)
	{
		for (p = head, pmin = head; p->next != NULL; p = p->next)
		{
			if (p->next->score < pmin->score)
			{
				pminBefore = p;
				pmin = p->next;//找出最大的链节
			}
		}

		if (pfirst == NULL)
		{
			pfirst = pmin;//将最大链节赋给pfirst指针
			ptail = pmin;
		}
		else
		{
			ptail->next = pmin;
			ptail = pmin;//逐渐拉开排序
		}
		//printf("\t%s\t%.2f\n", ptail->name, ptail->score);
		if (pmin == head)
		{
			head = head->next;//若最大的链节为head，则将head去掉
		}
		else
		{
			pminBefore->next = pmin->next;//去掉最大的链节后再进行排序，类似冒泡
		}
	}
	if (pfirst != NULL)
	{
		ptail->next = NULL;
	}
	head = pfirst;
	return head;
}
void wrifile(stu *head, char *fname, char xiuitem[][30])
{
	stu *current, *p, *first, *prev, *before;
	char  wname[40], wsex[5], wcoll[30], witem[20], fname1[20], ch, rname[40][30] = { 'a'};
	float wscore;
	int wmark, i, j, count[3] = { 0 };
	FILE *fp;
	p = NULL;
	first = NULL;
	prev = NULL;
	strcpy(fname1, fname);
	for (i = 0; fname1[i] != '.'; i++);
	fname1[i] = '\0';
	strcat(fname1, "c.txt");
	rename(fname, fname1);
	fp = fopen(fname, "w");
	for (i = 0, current = head, before = head; strcmp(xiuitem[i], "a") != 0; current = current->next)
	{
		if (current == NULL)
		{
			if (first == NULL)
			{
				p = head;
				break;
			}
			p->next = NULL;
			//printf("%s\t%s\n", first->name, p->name);
			current = head;
			i++;
		}
		if ((first != NULL) && (p != NULL) && (p->next == NULL))
		{
			if ((first->mark % 100) / 10 == 1)
				first = maxsort(first);
			else
				first = minsort(first);
			if (first->mark / 100 == 5)
				goal5(first);
			else
				goal3(first);
			for (p = first; p != NULL; p = p->next)
			{
				fprintf(fp, " %s %s %s %s %.2f %d ", p->name, p->sex, p->coll, p->item, p->score, p->mark);
				//printf(" %s %s %s %s %.2f %d ", p->name, p->sex, p->coll, p->item, p->score, p->mark);
			}
			chainfree(first);
			first = NULL;
			continue;
		}
		if (strcmp(xiuitem[i], current->item) == 0)
		{
			if (head == current)
				head = head->next;
			else
				count[1]++;
			if (first == NULL)
			{
				first = current;
			}
			else
			{
				p->next = current;
			}
			p = current;
		}
		if (current == head)
			before = head;
		else if (count[2] == count[1])
		{
			if(count[0]==0)
				before = before->next;
			else
			{
				before->next = current->next;
				before = current->next;
				count[0] = 0;
			}
		}
		else if(count[2] != count[1])
		{
			count[0]++;
		}
		count[2] = count[1];
	}
	for (p = head; p != NULL; p = p->next)
	{
		fprintf(fp, " %s %s %s %s %.2f %d ", p->name, p->sex, p->coll, p->item, p->score, p->mark);
		//printf(" %s %s %s %s %.2f %d ", p->name, p->sex, p->coll, p->item, p->score, p->mark);
	}
	getchar();
	getchar();
	chainfree(head);
	fclose(fp);
	remove(fname1);
}
