/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include "cjgl.h"
void wdisplay(void);
void write(void)
{
	system("cls");
	printf("ע�⣡¼��ʱ�벻Ҫ��;�˳�����\n");
	FILE *fp, *nf;
	stu * head, *prev, *current;
	char  wname[40], wsex[5], wcoll[30], witem[20], fname[20], fname1[20], ch, rname[40][30] = { 'a' };
	int a, b, wmark, i, j;
	float wscore;
	head = NULL;
	prev = NULL;
	current = NULL;
	printf("�������˶��������\n");
	scanf("%s", fname);
	strcpy(fname1, fname);
	strcat(fname1, "c.txt");
	strcat(fname, ".txt");
	//rename(fname, fname1);
	/*fp = fopen(fname, "a+");
	if (fp == NULL)
	{
		printf("�ļ��򿪴���\n");
		exit(EXIT_FAILURE);
	}*/
	/*printf("��������Ҫ¼�����Ŀ(���н���¼��)��\n");
	while (s_gets(witem, 45) != NULL && witem[0] != '\0')
	{
		rename(fname1, fname);//��ֹ��֮ǰ�û����淶�˳�ʹ��ʱ�ļ�������δ�޸Ķ���ɵ����ݶ�ʧ
		rename(fname, fname1);
		fp = fopen(fname1, "a+");
		if (fp == NULL)
		{
			printf("�ļ��򿪴���\n");
			exit(EXIT_FAILURE);
		}
		printf("���������Ŀ�Ļ����Σ�\n");
		scanf("%d", &a);
		printf("����Ŀ�ǵĺóɼ�Ϊ����ֵ���ǵ���ֵ��\n1������ֵ\n2������ֵ\n");
		scanf("%d", &b);
		printf("\n������%s�����ߵ����������н�������Ŀ���룩��\n", witem);
		while (s_gets(wname, 45) != NULL && wname[0] != '\0')
		{
			current = (stu*)malloc(sizeof(stu));
			if (head == NULL)
				head = current;
			else
				prev->next = current;
			strcpy(current->name, wname);
			strcpy(current->item, witem);
			printf("������%s���Ա�\n", wname);
			scanf("%s", current->sex);
			printf("������%s����ѧԺ��\n", wname);
			scanf("%s", current->coll);
			printf("������%s�ĳɼ���\n", wname);
			scanf("%f", &current->score);
			current->mark = 100 * a + 10 * b;
			printf("¼��ɹ���\n");
			prev = current;
			printf("\n������%s��һ�����ߵ����������н�������Ŀ¼�룩��\n", witem);
		}

		rewind(fp);
		fscanf(fp, "%s%s%s%s%f%d", wname, wsex, wcoll, witem, &wscore, &wmark);
		i = 0;
		while (!feof(fp))
		{
			if (!feof(fp))
				fscanf(fp, "%s%s%s%s%f%d", wname, wsex, wcoll, witem, &wscore, &wmark);
			if (strcmp(current->item, witem) == 0)
			{
				printf("%s\n", wname);
				strcpy(rname[i], wname);
				i++;
				current = (stu*)malloc(sizeof(stu));
				prev->next = current;
				strcpy(current->name, wname);
				strcpy(current->sex, wsex);
				strcpy(current->item, witem);
				strcpy(current->coll, wcoll);
				current->score = wscore;
				current->mark = wmark;
				prev = current;
			}
			while ((ch = getc(fp)) == ' ');//�Ե��ո񣬱����ж��ļ�ĩβ
			if (ch != ' '&&ch != EOF)
			{
				fseek(fp, -1L, SEEK_CUR);//��ָ�����һ�ֽڣ���ֹ����
			}
			//fscanf(fp, "%s%s%s%s%f%d", wname, wsex, wcoll, witem, &wscore, &wmark);
		}
		current->next = NULL;
		//chaincheck(head);
		if ((head->mark % 100) / 10 == 1)
		{
			head = maxsort(head);
			if (head->mark / 100 == 3)
				goal3(head);
			else
				goal5(head);
		}
		else
		{
			head = minsort(head);
			if (head->mark / 100 == 3)
				goal3(head);
			else
				goal5(head);

		}
		nf = fopen(fname, "w");
		//chaincheck(head);
		for (current = head; current != NULL; current = current->next)
		{
			fprintf(nf, " %s %s %s %s %.2f %d ", current->name, current->sex, current->coll, current->item, current->score, current->mark);
			//printf("%s %s %s %s %.2f %d\n ", current->name, current->sex, current->coll, current->item, current->score, current->mark);
			//fflush(fp);

		}
		rewind(fp);
		while (!feof(fp))
		{
			if (fscanf(fp, "%s%s%s%s%f%d", wname, wsex, wcoll, witem, &wscore, &wmark) != 6)
				break;
			for (current = head, j = 0; (current != NULL) && (!feof(fp)); current = current->next)
			{
				if (strcmp(current->name, wname) == 0)
					j++;
			}
			if (j == 0)
			{
				fprintf(nf, " %s %s %s %s %.2f %d ", wname, wsex, wcoll, witem, wscore, wmark);
				printf("\n %s %s %s %s %.2f %d \n", wname, wsex, wcoll, witem, wscore, wmark);
				fflush(fp);
			}
			while ((ch = getc(fp)) == ' ');//�Ե��ո񣬱����ж��ļ�ĩβ
			if (ch != ' '&&ch != EOF)
			{
				fseek(fp, -1L, SEEK_CUR);//��ָ�����һ�ֽڣ���ֹ����
			}
		}
		chainfree(head);
		head = NULL;
		fclose(fp);
		fclose(nf);
		remove(fname1);
		printf("��������һҪ¼�����Ŀ(���н���¼��)��\n");

	}

}*/