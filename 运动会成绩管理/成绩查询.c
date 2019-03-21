#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<io.h>
#include "cjgl.h"
void killdot(char *str);
void sdisplay1(void);
void sdisplay2(char tem[]);
void search2(void);
void seacol(char *colname);
void seaname(char *stuname);
typedef struct fen {
	char coll[40];
	int score;
	struct fen *next;
}fen;
struct fen *totalsort(fen *head);
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
	int select;
	select = 0;
	while (select != 4)
	{
		sdisplay1();
		while (scanf("%d", &select) != 1)
			printf("����������������룺\n");
		switch (select)
		{
		case 1:search2();
			break;
		case 2:
		{
			char colname[30];
			printf("������ѧԺ����\n");
			scanf("%s", colname);
			seacol(colname);
			break;
		}
		case 3:
		{
			char stuname[40];
			printf("������ѧ��������\n");
			scanf("%s", stuname);
			seaname(stuname);
			break;
		}
		case 4:
			break;
		case 5:
			exit(0);
		default:
			printf("����������1-5��\n");
		}
	}
}
void sdisplay2(char tem[])
{
	system("cls");
	printf("\t\t\t1��%s��ѧԺ�ֱܷ����ѯ\n",tem);
	printf("\t\t\t2��%s��ѧԺ�ɼ���ѯ\n",tem);
	printf("\t\t\t3��%s����˳ɼ���ѯ\n",tem);
	printf("\t\t\t4��%s�����Ŀ�ɼ���ѯ\n",tem);
	printf("\t\t\t5��%s��ȫ���ɼ�\n",tem);
	printf("\t\t\t6��������һ��\n");
	printf("\t\t\t7���˳�����\n");
	printf("����������1-7ִ�г���\n");
}
void search2(void)
{
	FILE *fp;
	int a, rank;
	char ch;
	char sname[40], tem[15], fname[30], scoll[40], sitem[30], rankitem[30] ;
	system("cls");
	printf("������Ҫ��ѯ�Ľ�����\n");
	scanf("%s",tem);
	strcpy(fname, tem);
	correctfile(fname);
	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		printf("�ļ������ڻ��޷���\n");
		exit(EXIT_FAILURE);
	}
	//sdisplay2(tem);
	sdisplay2(tem);
	int choice;
	while (scanf("%d", &choice) != 1)
		printf("����������������룺\n");
	stu *current, *prev, *head;
	current = NULL;
	head = NULL;
	prev = NULL;
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
	fclose(fp);
	//head=sort(head);
	while(choice!=6)
	{
		if (choice == 0)
		{
			sdisplay2(tem);
			while (scanf("%d", &choice) != 1)
				printf("����������������룺\n");
		}
		switch (choice)
		{
		case 1:
		{

			fen *first, *p, *bef, *point;
			int tp[30] = { 0 };
			int nc = 0, ic;
			stu  *q, *qpre;

			first = p = bef = NULL;
			current = head;
			if (NULL == first)
			{
				first = (fen*)malloc(sizeof(fen));
				strcpy(first->coll, current->coll);
				first->score = 0;
				bef = p = first;
			}
			for (q = qpre = head; q != NULL; qpre = q, q = q->next)
			{

				if (strcmp(current->coll, q->coll) != 0)
				{
					for (point = first, ic = 0; point != p->next; point = point->next)
					{
						if (strcmp(q->coll, point->coll) == 0)
							ic++;
					}
					if (ic > 0)
						continue;
					p = (fen*)malloc(sizeof(fen));
					bef->next = p;
					p->score = 0;
					strcpy(p->coll, q->coll);
					bef = p;
				}
			}
			p->next = NULL;
			for (p = first; p != NULL; p = p->next)
			{

				for (qpre = q = head; q != NULL; qpre = q, q = q->next)
				{
					if (strcmp(p->coll, q->coll) == 0)
					{
						if (((q->mark % 100) / 10 == 3 || (q->mark % 100) / 10 == 4) && strcmp(qpre->coll, q->coll) == 0 && strcmp(qpre->item, q->item) == 0)
						{
							if (q != head)
								continue;
						}
						p->score = p->score + (q->mark % 10);
					}
				}
			}
			first = totalsort(first);
			printf("\n");
			printf("ѧԺ\t\t�����ܷ�\t����\t\n");
			for (a = 1,p = first; p != NULL;a++)
			{
				color(a);
				printf("%s\t%d\t%10d\n", first->coll, first->score,a);
				color(4);
				first = p->next;
				free(p);
				p = first;
			}
			printf("\n");
			printf("����%s���ѯ�밴1\n��ѯ�������밴2\n�˳������밴3\n",tem);
			while (scanf("%d", &a) != 1)
				printf("����������������룺\n");
			if (a == 1)
			{
				choice = 0;
				break;
			}
			if (a == 2)
				choice = 6;
			if (a == 3)
				exit(0);
		}
		break;
		case 2://��ѧԺ���в�ѯ
		{
			a = 1;
			while (a == 1)
			{
				printf("������Ҫ��ѯ��ѧԺ���ƣ�\n\n");
				s_gets(scoll, 40);
				current = head;
				printf("����\t�Ա�\tѧԺ\t��Ŀ\t�ɼ�\t����\n");
				rank = 1;
				while (current != NULL)
				{
					if (strcmp(current->coll, scoll) == 0)
					{
						if (a == 1)
							printf("����\t�Ա�\tѧԺ\t��Ŀ\t�ɼ�\t����\n");
						if (strcmp(current->item, rankitem) != 0)
							rank = 1;
						else
						{
							if ((current->mark % 100) / 10 != 3 && (current->mark % 100) / 10 != 4)
								rank++;
						}
						printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", current->name, current->sex, current->coll, current->item, current->score,rank);
						a++;
						strcpy(rankitem, current->item);
					}
					current = current->next;
				}
				if (a == 1)
					printf("û�д�ѧԺ���������������\n");
				strcpy(rankitem, "a");
				printf("\n��������ѧԺ��ѯ�밴1\n����%s���ѯ�밴2\n��ѯ�������밴3\n�˳������밴4\n", tem);
				while (scanf("%d", &a) != 1)
					printf("����������������룺\n");
				switch (a)
				{
				case 1:
					break;
				case 2:choice = 0;
					break;
				case 3:choice = 6;
					break;
				case 4:exit(0);
				default:
					break;
				}
			}
		}
		break;
		case 3: //���������в�ѯ
		{
			a = 1;
			while (a == 1)
			{
				printf("������������\n\n");
				s_gets(sname, 40);
				current = head;
				rank = 1;
				while (current != NULL)
				{
					if (strcmp(current->name, sname) == 0)
					{
						if (a == 1)
							printf("����\t�Ա�\tѧԺ\t��Ŀ\t�ɼ�\t����\n");
						if (strcmp(current->item, rankitem) != 0)
							rank = 1;
						else
						{
							if ((current->mark % 100) / 10 != 3 && (current->mark % 100) / 10 != 4)
								rank++;
						}
						printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", current->name, current->sex, current->coll, current->item, current->score,rank);
						a++;
						strcpy(rankitem, current->item);
					}
					current = current->next;
				}
				if (a == 1)
					printf("���޴���\n");
				strcpy(rankitem, "a");
				printf("\n��������������ѯ�밴1\n����%s���ѯ�밴2\n��ѯ�������밴3\n�˳������밴4\n", tem);
				while (scanf("%d", &a) != 1)
					printf("����������������룺\n");
				switch (a)
				{
				case 1:
					break;
				case 2:choice = 0;
					break;
				case 3:choice = 6;
					break;
				case 4:exit(0);
				default:
					break;
				}
			}
		}
		break;
		case 4://����Ŀ���в�ѯ
		{
			a = 1;
			while (a == 1)
			{
				printf("��������Ŀ����(\033[1;31;47m���Ա�\033[0m����\033[1;31;47m����\033[0m���ߡ�\033[1;31;47mŮ��\033[0m��Զ)��\n\n");
				s_gets(sitem, 30);
				current = head;
				while (current != NULL)
				{
					if (strcmp(current->item, sitem) == 0)
					{
						if (a == 1)
							printf("����\t�Ա�\tѧԺ\t��Ŀ\t�ɼ�\t����\n");
						color(a);
						printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", current->name, current->sex, current->coll, current->item, current->score,a);
						color(4);
						a++;
					}
					current = current->next;
				}
				if (a == 1)
					printf("û�д���Ŀ��������������룡\n");
				printf("\n����������Ŀ��ѯ�밴1\n����%s���ѯ�밴2\n��ѯ�������밴3\n�˳������밴4\n", tem);
				while (scanf("%d", &a) != 1)
					printf("����������������룺\n");
				switch (a)
				{
				case 1:
					break;
				case 2:choice = 0;
					break;
				case 3:choice = 6;
					break;
				case 4:exit(0);
				default:
					break;
				}
			}
		}
		break;
		case 5://����ý�ȫ���ɼ�
		{
			char mitem[30][30] = { 'a' }, rankcoll[30];
			int n = 0, i;
			printf("����\t�Ա�\tѧԺ\t\t��Ŀ\t\t�ɼ�\t����\n");
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
				for (rank = 1,a = 1; current != NULL;)
				{
					if (strcmp(mitem[i], current->item) == 0)
					{
						if (a != 1)
						{
							if (((current->mark % 100) / 10 == 3 || (current->mark % 100) / 10 == 4) && strcmp(rankcoll, current->coll) != 0)
								rank++;
						}
						color(rank);
						printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", current->name, current->sex, current->coll, current->item, current->score,rank);
						color(4);
						strcpy(rankcoll, current->coll);
						if ((current->mark % 100) / 10 != 3 && (current->mark % 100) / 10 != 4)
							rank++;
						a++;
					}
					current = current->next;
				}
				current = head;
			}
			a = 1;
			printf("\n����%s���ѯ�밴1\n��ѯ�������밴2\n�˳������밴3\n", tem);
			while (scanf("%d", &a) != 1)
				printf("����������������룺\n");
			switch (a)
			{
			case 1:choice = 0;
				break;
			case 2:choice = 6;
				break;
			case 3:exit(0);
			default:
				break;
			}
		}
		break;
		case 7:exit(0);
		}
	}
	chainfree(head);
}
void seacol(char *colname)
{

	long Handle;
	FILE *fp;
	char scname[40], scsex[5], scitem[30], sccol[40], str[20], rankitem[30];
	float scsco;
	int  scmark, rank;
	struct _finddata_t FileInfo;

	if ((Handle = _findfirst("*.txt", &FileInfo)) == -1L)

		printf("�����˶���ɼ��������¼��\n");

	else

	{

		//printf("%s\n", FileInfo.name);
		strcpy(str, FileInfo.name);
		killdot(str);
		printf("%s:\n", str);
		printf("����\t�Ա�\tѧԺ\t\t��Ŀ\t\t�ɼ�\t����\n");
		fp = fopen(FileInfo.name, "r + ");
		rank = 1;
		while (!feof(fp))
		{
			if (fscanf(fp, "%s%s%s%s%f%d", scname, scsex, sccol, scitem, &scsco, &scmark) != 6)
				break;
			if (strcmp(scitem, rankitem) != 0)
				rank = 1;
			else
			{
				if ((scmark % 100) / 10 != 3 && (scmark % 100) / 10 != 4)
					rank++;
			}
			if (strcmp(sccol, colname) == 0)
				printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", scname, scsex, sccol, scitem, scsco, rank);
			strcpy(rankitem, scitem);
		}
		fclose(fp);
		//printf('\n');
		while (_findnext(Handle, &FileInfo) == 0)
		{
			//printf("%s\n", FileInfo.name);
			strcpy(str, FileInfo.name);
			killdot(str);
			printf("%s:\n", str);
			printf("����\t�Ա�\tѧԺ\t\t��Ŀ\t\t�ɼ�\t����\n");
			fp = fopen(FileInfo.name, "r+");
			rank = 1;
			while (!feof(fp))
			{
				if (fscanf(fp, "%s%s%s%s%f%d", scname, scsex, sccol, scitem, &scsco, &scmark) != 6)
					break;
				if (strcmp(scitem, rankitem) != 0)
					rank = 1;
				else
				{
					if ((scmark % 100) / 10 != 3 && (scmark % 100) / 10 != 4)
						rank++;
				}
				if (strcmp(sccol, colname) == 0)
					printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", scname, scsex, sccol, scitem, scsco, rank);
				strcpy(rankitem, scitem);
			}
			fclose(fp);
			while (getchar() != '\n');
			//printf('\n');
		}
		_findclose(Handle);

	}
}
void seaname(char *stuname)
{

	long Handle;
	FILE *fp;
	char scname[40], scsex[5], scitem[30], sccol[40], str[20], rankitem[30];
	float scsco;
	int  scmark, rank;
	struct _finddata_t FileInfo;

	if ((Handle = _findfirst("*.txt", &FileInfo)) == -1L)

		printf("�����˶���ɼ��������¼��\n");

	else

	{

		//printf("%s\n", FileInfo.name);
		strcpy(str, FileInfo.name);
		killdot(str);
		printf("%s:\n", str);
		printf("����\t�Ա�\tѧԺ\t\t��Ŀ\t\t�ɼ�\t����\n");
		//printf("%s:\n", str);
		fp = fopen(FileInfo.name, "r + ");
		rank = 1;
		while (!feof(fp))
		{
			if (fscanf(fp, "%s%s%s%s%f%d", scname, scsex, sccol, scitem, &scsco, &scmark) != 6)
				break;
			if (strcmp(scitem, rankitem) != 0)
				rank = 1;
			else
			{
				if ((scmark % 100) / 10 != 3 && (scmark % 100) / 10 != 4)
					rank++;
			}
			if (strcmp(scname, stuname) == 0)
			{
				printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", scname, scsex, sccol, scitem, scsco,rank);
			}
			strcpy(rankitem, scitem);
		}
		fclose(fp);
		//printf('\n');
		while (_findnext(Handle, &FileInfo) == 0)
		{
			//printf("%s\n", FileInfo.name);
			strcpy(str, FileInfo.name);
			killdot(str);
			//printf("%s:\n", str);
			printf("%s:\n", str);
			printf("����\t�Ա�\tѧԺ\t\t��Ŀ\t\t�ɼ�\t����\n");
			fp = fopen(FileInfo.name, "r+");
			rank = 1;
			while (!feof(fp))
			{
				if (fscanf(fp, "%s%s%s%s%f%d", scname, scsex, sccol, scitem, &scsco, &scmark) != 6)
					break;
				if (strcmp(scitem, rankitem) != 0)
					rank = 1;
				else
				{
					if ((scmark % 100) / 10 != 3 && (scmark % 100) / 10 != 4)
						rank++;
				}
				if (strcmp(scname, stuname) == 0)
				{
					printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", scname, scsex, sccol, scitem, scsco,rank);
				}
				strcpy(rankitem, scitem);
			}
			fclose(fp);
			while (getchar() != '\n');
			//printf('\n');
		}
		_findclose(Handle);

	}
}
void killdot(char *str)
{
	int i;
	for (i = 0; str[i] != '.'; i++);
	str[i] = '\0';
	//return  str;
}
struct fen *totalsort(fen *head)//�ú����Ǵ�1��������������ŷ�
{
	fen *pfirst = NULL;
	fen *ptail = NULL;
	fen *pmaxBefore = NULL;
	fen *pmax = NULL;
	fen *p = NULL;
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