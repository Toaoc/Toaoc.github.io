#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include "cjgl.h"
void dele(void)
{
	system("cls");
	stu *p, *q, *head, *current, *prev;
	p = NULL;
	q = NULL;
	head = NULL;
	current = NULL;
	prev = NULL;
	//p=head;
	//p=q=(struct Student*)malloc(LEN);
	FILE *fin;
	int i, j, k;
	j = 0;
	k = 0;
	char ch[30], ch1[30], aname[30], asex[5], acoll[30], aitem[30], fname[20], ofname[20];
	int amark, arr[30] = { 0 }, choice = 1, select = 0;
	char xiuitem[30][30] = { "a" };
	float ascore;
	//char a[1000];
	printf("������Ҫ�޸ĵ���ݣ�\n");
	scanf("%s", fname);
	correctfile(fname);
	fin = fopen(fname, "r");
	if (fin == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		exit(0);
	}
	else
		printf("������Ҫɾ������������μӵ���Ŀ(�磺����  ������Զ):\n");
	scanf("%s%s", ch, ch1);
	//fgets(a,1000,fin);
	for (i = 0; feof(fin) == 0; i++)
	{
		if (fscanf(fin, "%s%s%s%s%f%d", aname, asex, acoll, aitem, &ascore, &amark) != 6)
		{
			if (i == 0)
			{
				printf("�ý�ɼ�δ¼�룬��ý���Ϣ�ѱ��ƻ�\n");
				exit(1);
			}
			break;
		}
		current = (stu*)malloc(sizeof(stu));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		strcpy(current->name, aname);//���⿪ʼ�������ǽ����ļ����������ݸ��Ƶ�������
		strcpy(current->sex, asex);
		strcpy(current->coll, acoll);
		strcpy(current->item, aitem);
		current->score = ascore;
		current->mark = amark;
		prev = current;

	}
	current->next = NULL;
	while (choice != 2)
	{
		p = q = head;
		//for(i=0;i<1000;i++)
		//{
		while (strcmp(p->name, ch) != 0 || strcmp(p->item, ch1) != 0)
		{
			q = p;
			p = p->next;
			if (p->next == NULL)
			{
				break;
			}
			//printf("%s %s\n", p->name, p->coll);
		}
		if (strcmp(p->name, ch) == 0 && strcmp(p->item, ch1) == 0)
		{
			printf("\n%s\t%s\t%s\t%s\t%.2f\n", p->name, p->sex, p->coll, p->item, p->score);
			printf("\nȷ��ɾ����\n1.ɾ��\n2.��ɾ��\n");
			while (scanf("%d", &choice) != 1||(choice != 1&&choice != 2))
				printf("�����������������");
			if (choice == 1)
			{
				arr[k] = p->mark % 10;
				if (arr[k] != 0)
				{
					strcpy(xiuitem[j], p->item);
					strcpy(xiuitem[j + 1], "a");
					j++;
				}
				k++;
				if (p == head)
					head = head->next;
				else
					q->next = p->next;
			}
		}
		else
			printf("%s����Ϣ��δ¼�룡\n", ch);
		printf("����ɾ���밴1\n������һ���밴2\n�˳������밴3\n");
		while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2 && choice != 3))
			printf("����������������룡\n");
		if (choice == 3)
		{
			choice = 2;
			select = 3;
		}
	}
	//fclose(fin);
	//fin = fopen("2018.txt", "w");
	/*if (j != 0)
		strcpy(xiuitem[j], "a");*/
	for (i = j = 0; i < 29; i++)
	{
		j = arr[i] + j;
		//printf("%s\n", xiuitem[i]);
	}
	if (j != 0)
	{
		fclose(fin);
		wrifile(head, fname, xiuitem);
		printf("ɾ���ɹ���\n");
	}
	else
	{
		for (p = head; p != NULL; p = p->next)
			fprintf(fin, " %s %s %s %s %.2f %d ", p->name, p->sex, p->coll, p->item, p->score, p->mark);
		fclose(fin);
		chainfree(head);
	}
	if (select == 3)
		exit(0);
}