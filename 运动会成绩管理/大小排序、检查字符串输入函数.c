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
				pmin = p->next;//�ҳ���С������
			}
		}

		if (pfirst == NULL)
		{
			pfirst = pmin;//����С���ڸ���pfirstָ��
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
			head = head->next;//����С������Ϊhead����headȥ��
		}
		else
		{
			pminBefore->next = pmin->next;//ȥ����С�����ں��ٽ�����������ð��
		}
	}
	if (pfirst != NULL)
	{
		ptail->next = NULL;
	}
	head = pfirst;
	return head;
}
void wrifile(stu *head, char *fname, char xiuitem[][30])//�����޸ĺ�ɾ��ģ����ļ�д�룬fname��ʾ�޸ĵ��ļ�����xiuname��ʾ�޸ĵ���Ŀ�����ж����
{
	stu *current, *p, *first, *prev, *before;
	char  wname[40], wsex[5], wcoll[30], witem[20], fname1[20], ch;//��w�Ķ�����ʱ��
	float wscore;
	int wmark, i, j, count[3] = { 0 };//count���ڼ���ͬ��Ŀ���ж��ٸ����Ӷ�ȷ��before->next����һ��
	FILE *fp;
	p = NULL;
	first = NULL;
	prev = NULL;
	strcpy(fname1, fname);
	for (i = 0; fname1[i] != '.'; i++);
	fname1[i] = '\0';
	strcat(fname1, "c.txt");
	rename(fname, fname1);//��ԭ�ļ���Ϊ�м��ļ�
	fp = fopen(fname, "w");//��ʱ��򿪵���һ���µġ��յ��ļ�
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
		if ((first != NULL) && (p != NULL) && (p->next == NULL))//���򡢸��ֺ�д���ļ�
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
		if (strcmp(xiuitem[i], current->item) == 0)//����һ����������ԭ�����ϵ�ͬ�޸���Ŀ����Ŀװ����������
		{
			if (head == current)
				head = head->next;
			else
				count[1]++;//���ڼ�¼���˶��ٸ�
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
			before = head;//ʹbeforeָ���Ϊcurrent��ǰָ��
		else if (count[2] == count[1])//��û�ж�ȡ��Ŀ
		{
			if(count[0]==0)//�ж�����һ���Ƿ��ж�ȡ
				before = before->next;
			else
			{
				before->next = current->next;
				before = current->next;
				count[0] = 0;//��������ȡ��������
			}
		}
		else if(count[2] != count[1])
		{
			count[0]++;//�ж�������ȡ�Ĵ���
		}
		count[2] = count[1];//ʹ��������ȣ��Ӷ��ж���һ����ȡ
	}
	for (p = head; p != NULL; p = p->next)//��������Ŀд�뵽�ļ���
	{
		fprintf(fp, " %s %s %s %s %.2f %d ", p->name, p->sex, p->coll, p->item, p->score, p->mark);
	}
	chainfree(head);
	fclose(fp);
	remove(fname1);//���м��ļ�ȥ��
}
