#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include "cjgl.h"
void sdisplay1(void);
void sdisplay2(char tem[]);
void search2(void);
void sdisplay1(void)
{
	system("cls");
	printf("***********************�˶���ɼ�����ϵͳ*********************\n");
	printf("\t\t\t1.��У�˻������ѯ\n");
	printf("\t\t\t2.��ѯ��ѧԺ����У�˻�������\n");
	printf("\t\t\t3.��ѯѧ������У�˻�������\n");
	printf("\t\t\t4.������һ��\n");
	printf("\t\t\t5.�˳�����\n");
	printf("����������1-5ִ�г���\n");
}

void search(void)
{
	sdisplay1();
	int select;
	scanf("%d", &select);
	switch (select)
	{
	case 1:search2();
	}
}
void sdisplay2(char tem[])
{
	system("cls");
	printf("\t\t\t1��%s��ѧԺ�ֱܷ���\n",tem);
	printf("\t\t\t2��%s��ѧԺ�ɼ���ѯ\n",tem);
	printf("\t\t\t3��%s����˳ɼ���ѯ\n",tem);
	printf("\t\t\t4��%s�����Ŀ�ɼ���ѯ\n",tem);
	printf("\t\t\t5��%s��ȫ���ɼ�\n",tem);
	printf("\t\t\t6��������һ��\n");
	printf("\t\t\t7���˳�����\n");
	printf("ע�⣺�ڱ��γ���������¼��ĳɼ��������󷽿ɲ�ѯ\n");
	printf("����������1-7ִ�г���\n");
}
void search2(void)
{
	FILE *fp;
	int a = 1;
	char ch;
	char sname[40], tem[15], fname[30];
	printf("������Ҫ��ѯ�Ľ�����\n");
	scanf("%s",tem);
	sdisplay2(tem);
	int choice;
	scanf("%d", &choice);
	FILE *fp;
	int a = 1;
	char ch;
	char sname[40];
	stu *current, *prev, *head;
	current = NULL;
	head = NULL;
	prev = NULL;
	fp = fopen("�ɼ�.txt", "r+");
	if (fp == NULL)
	{
		printf("�ļ��޷���\n");
		exit(EXIT_FAILURE);
	}
	while (!feof(fp))
	{
		current = (stu*)malloc(sizeof(stu));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		fscanf(fp, "%s%s%s%s%f%d", current->name, current->sex, current->coll, current->item, &current->score, &current->mark);
		prev = current;
		while ((ch = getc(fp)) == ' ');//�Ե��ո񣬱����ж��ļ�ĩβ
		if (ch != ' '&&ch != EOF)
		{
			fseek(fp, -1L, SEEK_CUR);//��ָ�����һ�ֽڣ���ֹ����
		}
	}
	current->next = NULL;
	//head=sort(head);
	switch (choice)
	{
	case 3: //���������в�ѯ
		while (a == 1)
		{
			printf("������������\n");
			s_gets(sname, 40);
			current = head;
			while (current != NULL)
			{
				if (strcmp(current->name, sname) == 0)
				{
					printf("%s\t%s\t%s\t%s\t%.2f\n", current->name, current->sex, current->coll, current->item, current->score);
					a++;
				}
				current = current->next;
			}
			if (a == 1)
				printf("���޴���\n");
			printf("������ѯ�밴1\n������һ���밴2\n�˳������밴3\n");
			scanf("%d", &a);
			if (a == 3)
				exit(0);
		}
		break;
	case 7:
	{
		char mitem[30][30] = { 'a' };
		int n = 0, i;
		current = head;
		strcpy(mitem[0], current->item);
		while (current != NULL)
		{
			for (i = 0; i < n + 1; i++)
			{
				if (strcmp(mitem[i], current->item) != 0 && i == n)
				{
					strcpy(mitem[n + 1], current->item);
					n++;
				}
				else if (strcmp(mitem[i], current->item) == 0)
				{
					break;
				}
			}
			current = current->next;
		}
		for (current = head, i = 0; current != NULL && i < n + 1; i++)
		{
			for (; current != NULL;)
			{
				if (strcmp(mitem[i], current->item) == 0)
				{
					printf("%s\t%s\t%s\t%s\t%.2f\n", current->name, current->sex, current->coll, current->item, current->score);
				}
				current = current->next;
			}
			current = head;
		}
		printf("������һ���밴1\n�˳������밴2\n");
		scanf("%d", &a);
		if (a == 2)
			exit(0);
	}
	case 8:exit(0);
	}
	fclose(fp);
}