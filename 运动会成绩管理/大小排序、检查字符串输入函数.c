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
				pmin = p->next;//找出最小的链节
			}
		}

		if (pfirst == NULL)
		{
			pfirst = pmin;//将最小链节赋给pfirst指针
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
			head = head->next;//若最小的链节为head，则将head去掉
		}
		else
		{
			pminBefore->next = pmin->next;//去掉最小的链节后再进行排序，类似冒泡
		}
	}
	if (pfirst != NULL)
	{
		ptail->next = NULL;
	}
	head = pfirst;
	return head;
}
void wrifile(stu *head, char *fname, char xiuitem[][30])//用于修改和删除模块的文件写入，fname表示修改的文件名，xiuname表示修改的项目（可有多个）
{
	stu *current, *p, *first, *prev, *before;
	char  wname[40], wsex[5], wcoll[30], witem[20], fname1[20], ch;//带w的都是临时的
	float wscore;
	int wmark, i, j, count[3] = { 0 };//count用于计算同项目的有多少个，从而确定before->next是哪一个
	FILE *fp;
	p = NULL;
	first = NULL;
	prev = NULL;
	strcpy(fname1, fname);
	for (i = 0; fname1[i] != '.'; i++);
	fname1[i] = '\0';
	strcat(fname1, "c.txt");
	rename(fname, fname1);//将原文件改为中间文件
	fp = fopen(fname, "w");//这时候打开的是一个新的、空的文件
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
		if ((first != NULL) && (p != NULL) && (p->next == NULL))//排序、赋分后写入文件
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
			}
			chainfree(first);
			first = NULL;
			continue;
		}
		if (strcmp(xiuitem[i], current->item) == 0)//建立一个新链表，把原链表上的同修改项目的项目装到新链表中
		{
			if (head == current)
				head = head->next;
			else
				count[1]++;//用于记录读了多少个
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
			before = head;//使before指针成为current的前指针
		else if (count[2] == count[1])//即没有读取项目
		{
			if(count[0]==0)//判断其上一个是否有读取
				before = before->next;
			else
			{
				before->next = current->next;
				before = current->next;
				count[0] = 0;//将连续读取计数归零
			}
		}
		else if(count[2] != count[1])
		{
			count[0]++;//判断连续读取的次数
		}
		count[2] = count[1];//使这两个相等，从而判断下一个读取
	}
	for (p = head; p != NULL; p = p->next)//将其余项目写入到文件中
	{
		fprintf(fp, " %s %s %s %s %.2f %d ", p->name, p->sex, p->coll, p->item, p->score, p->mark);
	}
	chainfree(head);
	fclose(fp);
	remove(fname1);//将中间文件去掉
}
