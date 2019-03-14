#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "cjgl.h"
char *s_gets(char *st, int n)
{
	char *re, *find;
	char c;
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
struct stu *maxsort(stu *head)//�ú����Ǵ�1��������������ŷ�
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
				pmax = p->next;//�ҳ���������
			}
		}

		if (pfirst == NULL)
		{
			pfirst = pmax;//��������ڸ���pfirstָ��
			ptail = pmax;
		}
		else
		{
			ptail->next = pmax;
			ptail = pmax;//����������
		}
		//printf("\t%s\t%.2f\n", ptail->name, ptail->score);
		if (pmax == head)
		{
			head = head->next;//����������Ϊhead����headȥ��
		}
		else
		{
			pmaxBefore->next = pmax->next;//ȥ���������ں��ٽ�����������ð��
		}
	}
	if (pfirst != NULL)
	{
		ptail->next = NULL;
	}
	head = pfirst;
	return head;
}
struct stu *minsort(stu *head)//�ú����Ǵ�1��������������ŷ�
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
				pmin = p->next;//�ҳ���������
			}
		}

		if (pfirst == NULL)
		{
			pfirst = pmin;//��������ڸ���pfirstָ��
			ptail = pmin;
		}
		else
		{
			ptail->next = pmin;
			ptail = pmin;//����������
		}
		//printf("\t%s\t%.2f\n", ptail->name, ptail->score);
		if (pmin == head)
		{
			head = head->next;//����������Ϊhead����headȥ��
		}
		else
		{
			pminBefore->next = pmin->next;//ȥ���������ں��ٽ�����������ð��
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
	char  wname[40], wsex[5], wcoll[30], witem[20], fname1[20], ch, rname[40][30] = { 'a' };
	float wscore;
	int wmark, i, j;
	FILE *fp;
	p = NULL;
	first = NULL;
	prev = NULL;
	fname1[0] = 'c';
	fname1[1] = '\0';
	strcat(fname1, fname);
	rename(fname1, fname);//��ֹ��֮ǰ�û����淶�˳�ʹ��ʱ�ļ�������δ�޸Ķ���ɵ����ݶ�ʧ
	rename(fname, fname1);
	fp = fopen(fname, "w+");
	for (i = 0, current = head, before = head; strcmp(xiuitem[i], "a") != 0; before = current, current = current->next)
	{
		if (current != NULL)
		{
			printf("%s\n", current->item);
		}
		if (current == NULL)
		{
			printf("NULL\n");
			p->next = NULL;
			printf("%s\t%s\n", first->name, p->name);
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
				printf(" %s %s %s %s %.2f %d ", p->name, p->sex, p->coll, p->item, p->score, p->mark);
			}
			chainfree(first);
			first = NULL;
			continue;
		}
		if (strcmp(xiuitem[i], current->item) == 0)
		{
			if (first == NULL)
			{
				first = current;
			}
			else
			{
				p->next = current;
			}
			p = current;
			if (head == current)
				head = head->next;
			else
				before->next = current->next;
		}
	}
	for (p = head; p != NULL; p = p->next)
	{
		fprintf(fp, " %s %s %s %s %.2f %d ", p->name, p->sex, p->coll, p->item, p->score, p->mark);
	}
	chainfree(head);
	fclose(fp);
	remove(fname1);
}
