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

