#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include "cjgl.h"
void wdisplay(void);
void ensex(char *witem,char *wsex);
void singlewrite(char*fname);
void teamwrite(char*fname);
int get2(char *str);
void enter(void)
{
	char fname[30];
	int choice;
	choice = -1;
	while (choice != 3)
	{
		printf("������Ҫ¼�����ݣ�\n");
		scanf("%s", fname);
		system("cls");
		printf("\t\t\t1��������Ŀ¼��\n");
		printf("\t\t\t2��������Ŀ¼��\n");
		printf("\t\t\t3��������һ��\n");
		printf("\t\t\t4���˳�����\n");
		printf("����������1-4ִ�г���");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:singlewrite(fname);
			break;
		case 2:teamwrite(fname);
			break;
		case 3:
			break;
		case 4:exit(0);
			break;
		default:printf("����������1-4ִ�г���");
		}
		if (choice == 1 || choice == 2)
			break;
	}
}
void ensex(char *witem,char *wsex)
{
	int i;
	for (i = 0; i != 2; i++)
		wsex[i] = witem[i];
	wsex[i] = '\0';
	printf("%s\t%s\n", witem, wsex);
}
void singlewrite(char *fname)
{
	//system("cls");
	//printf("ע�⣡¼��ʱ�벻Ҫ��;�˳�����\n");
	FILE *fp, *nf;
	stu * head, *prev, *current;
	char  wname[40], wsex[5], wcoll[30], witem[20], fname1[20], ch, rname[40][30] = { 'a' };
	int a, b, wmark, i, j, k, n;
	float wscore;
	head = NULL;
	prev = NULL;
	current = NULL;
	/*printf("�������˶��������\n");
	scanf("%s", fname);*/
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
	for (k = 0;k!=-1; k++)
	{
		printf("��������Ҫ¼�����Ŀ(\033[1;31;47m���Ա� \033[0m����������Զ��Ů�����ߣ���\n");
		scanf("%s", witem);
		ensex(witem, wsex);
		if (strcmp(wsex, "��") == 0 || strcmp(wsex, "Ů") == 0)
			break;
		else
			printf("������Ŀ�Ƿ�����Ա���������룺\n");
	}
	while (1)
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
			strcpy(current->sex, wsex);
			printf("%s\n", current->sex);
			/*printf("������%s���Ա�\n", wname);
			scanf("%s", current->sex);*/
			printf("������%s����ѧԺ��\n", wname);
			scanf("%s", current->coll);
			printf("������%s�ĳɼ���\n", wname);
			scanf("%f", &current->score);
			current->mark = 100 * a + 10 * b;
			printf("¼��ɹ���\n");
			prev = current;
			printf("������%s��һ�����ߵ����������н�������Ŀ¼�룩��\n", witem);
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
		printf("��������Ҫ¼�����Ŀ(���Ա���������Զ��Ů�����ߣ���\n");
		n = get2(witem);
		if (n == 0)
			break;
		for (k = 0;; k++)
		{
			if (k > 0)
			{
				printf("��������Ҫ¼�����Ŀ(���Ա���������Զ��Ů�����ߣ���\n");
				scanf("%s", witem);
			}
			ensex(witem, wsex);
			if (strcmp(wsex, "��") != 0 || strcmp(wsex, "Ů") != 0)
				break;
			else
				printf("������Ŀ�Ƿ�����Ա���������룺\n");
		}

	}

}
void teamwrite(char*fname)
{
	//system("cls");
	//printf("ע�⣡¼��ʱ�벻Ҫ��;�˳�����\n");
	FILE *fp, *nf;
	stu * head, *prev, *current;
	char  wname[40], wsex[5], wcoll[30], witem[20], fname1[20], ch, rname[40][30] = { 'a' };
	int a, b, wmark, i, j, k, n, c;
	float wscore;
	head = NULL;
	prev = NULL;
	current = NULL;
	//printf("�������˶��������\n");
	//scanf("%s", fname);
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
	for (k = 0; k != -1; k++)
	{
		printf("��������Ҫ¼���������Ŀ(���Ա�����������Ů�����򣩣�\n");
		scanf("%s", witem);
		ensex(witem, wsex);
		if (strcmp(wsex, "��") == 0 || strcmp(wsex, "Ů") == 0)
			break;
		else
			printf("������Ŀ�Ƿ�����Ա���������룺\n");
	}
	while (1)
	{
		rename(fname1, fname);//��ֹ��֮ǰ�û����淶�˳�ʹ��ʱ�ļ�������δ�޸Ķ���ɵ����ݶ�ʧ
		rename(fname, fname1);
		fp = fopen(fname1, "a+");
		if (fp == NULL)
		{
			printf("�ļ��򿪴���\n");
			exit(EXIT_FAILURE);
		}
		printf("������%s�Ļ����Σ�\n", witem);
		scanf("%d", &a);
		printf("%s��1-%d���Ƿ���ֵ�ɼ�ͳһ������\n1����\n2����\n", witem, a);
		scanf("%d", &c);
		if (1 == c)
			b = c + 1;
		else
			b = 5;
		if (2 == b)
		{
			printf("%s�ĺóɼ�Ϊ����ֵ���ǵ���ֵ��\n1������ֵ\n2������ֵ\n", witem);
			scanf("%d", &c);
			b = b + c;
		}
		//printf("\n������%s�����ߵ����������н�������Ŀ���룩��\n", witem);
		printf("������%s����ѧԺ�����ƣ�\n", witem);
		getchar();
		while (s_gets(wcoll, 45) != NULL && wcoll[0] != '\0')
		{
			if (3 == b || 4 == b)
			{
				printf("������%s�ĳɼ���\n", wcoll);
				scanf("%f", &wscore);
			}
			else
			{
				printf("������%s��õ����Σ�\n", wcoll);
				scanf("%f", &wscore);
				b = 4;
			}
			printf("������%s��ѡ�֣�\n", wcoll);
			getchar();
			while (s_gets(wname,45) != NULL && wname[0] != '\0')
			{
				current = (stu*)malloc(sizeof(stu));
				if (head == NULL)
					head = current;
				else
					prev->next = current;
				strcpy(current->coll, wcoll);
				strcpy(current->item, witem);
				strcpy(current->sex, wsex);
				strcpy(current->name, wname);
				current->score = wscore;
				//printf("%s\n", current->sex);
				/*printf("������%s���Ա�\n", wname);
				scanf("%s", current->sex);*/
				/*printf("������%s��ѡ�֣�\n", wcoll);
				scanf("%s", current->coll);*/
				/*printf("������%s�ĳɼ���\n", wcoll);
				scanf("%f", &current->score);*/
				current->mark = 100 * a + 10 * b;
				//printf("¼��ɹ���\n");
				prev = current;
				printf("������%s��һѡ�ֵ����������н������룩��\n", wcoll);
			}
			printf("\n������%s��һ����ѧԺ�����ƣ����н�������Ŀ¼�룩��\n", witem);
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
		if ((head->mark % 100) / 10 == 1 || (head->mark % 100) / 10 == 3)
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
		n = get2(witem);
		if (n == 0)
			break;
		for (k = 0;; k++)
		{
			if (k > 0)
			{
				printf("��������Ҫ¼�����Ŀ(���Ա�����������Ů�����򣩣�\n");
				scanf("%s", witem);
			}
			ensex(witem, wsex);
			if (strcmp(wsex, "��") != 0 || strcmp(wsex, "Ů") != 0)
				break;
			else
				printf("������Ŀ�Ƿ�����Ա���������룺\n");
		}

	}

}
int get2(char *str)
{
	char ch;
	int i;
	for (i = 0; (ch = getchar()) != '\n'; i++)
	{
		str[i] = ch;
	}
	str[i] = '\0';
	return i;
}