#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
void chaincheck(struct stu*head);
void display(void);//��������ʾ����
void search(void);
void write(void);
void alter(void);
void sdisplay(void);
void wdisplay(void);
void adisplay(void);
struct stu *minsort(struct stu * head);
void goal3(struct stu * head);
void goal5(struct stu * head);
void chainfree(struct stu * head);
struct stu *maxsort(struct stu * head);
char *s_gets(char *st, int n);
typedef struct stu {
	char name[40];
	char sex[5];
	char coll[40];
	char item[30];
	float score;
	int mark;//�����
	struct stu *next;
}stu;
int main(void)
{
	int a = 0;
	while (a != 4)
	{
		display();
		scanf("%d", &a);
		switch (a)
		{
		case 1:search();
			break;
		case 2:write();
			break;
		case 3:alter();
			break;
		case 4:exit(0);
			break;
		default:printf("�����������������1��2��3��");
		}
	}
	return 0;

}
void display(void)
{
	printf("***********************�˶���ɼ�����ϵͳ*********************\n");
	printf("\t\t\t1.�ɼ���ѯ\n");
	printf("\t\t\t2.�ɼ�¼��\n");
	printf("\t\t\t3.�޸ĳɼ�\n");
	printf("\t\t\t4.�˳�\n");
	printf("����������1-4ִ�г���:\n");
}
void write(void)
{
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
	rename(fname, fname1);
	/*fp = fopen(fname, "a+");
	if (fp == NULL)
	{
		printf("�ļ��򿪴���\n");
		exit(EXIT_FAILURE);
	}*/
	printf("��������Ҫ¼�����Ŀ(���н���¼��)��\n");
	while (s_gets(witem, 45) != NULL && witem[0] != '\0')
	{
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
			fscanf(fp, "%s%s%s%s%f%d", wname, wsex, wcoll, witem, &wscore, &wmark);
		}
		current->next = NULL;
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
			if (!feof(fp))
				fscanf(fp, "%s%s%s%s%f%d", wname, wsex, wcoll, witem, &wscore, &wmark);
			for (current = head, j = 0; (current != NULL) && (!feof(fp)); current = current->next)
			{
				if (strcmp(current->name, wname) == 0)
					j++;
			}
			if (j == 0)
			{
				fprintf(nf, " %s %s %s %s %.2f %d ", wname, wsex, wcoll, witem, wscore, wmark);
				printf("\n %s %s %s %s %.2f %d \n", wname, wsex, wcoll, witem, wscore, wmark);
				//fflush(fp);
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

}
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
void sdisplay(void)
{
	printf("\t\t\t1��ѧԺ�ֱܷ���\n");
	printf("\t\t\t2��ѧԺ�ɼ���ѯ\n");
	printf("\t\t\t3�����˳ɼ���ѯ\n");
	printf("\t\t\t4������Ŀ�ɼ���ѯ\n");
	printf("\t\t\t5���������ȫ���ɼ�\n");
	printf("\t\t\t6�����ȫ���ɼ�\n");
	printf("\t\t\t7��������һ��\n");
	printf("\t\t\t8���˳�����\n");
	printf("ע�⣺�ڱ��γ���������¼��ĳɼ��������󷽿ɲ�ѯ\n");
	printf("����������1-7ִ�г���\n");
}
void search(void)
{
	system("cls");
	sdisplay();
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
	case 6:
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
void adisplay(void)
{
	printf("\t\t\t1���޸ĳɼ�\n");
	printf("\t\t\t2��ɾ���ɼ�\n");
	printf("\t\t\t3��������һ��\n");
	printf("\t\t\t4���˳�����\n");
	printf("����������1-4��ִ�г���\n");
}
void alter(void)//�޸ĳɼ��ĺ���
{
	adisplay();
	int choice, len;
	char aname[40], ch;
	FILE *fp;
	stu *current;
	current = NULL;
	current = (stu*)malloc(sizeof(stu));
	fp = fopen("�ɼ�.txt", "r+");
	if (fp == NULL)
	{
		printf("�ļ��򿪴���\n");
		exit(EXIT_FAILURE);
	}
	fscanf(fp, "%s%s%s%s%f", current->name, current->sex, current->coll, current->item, &current->score);
	scanf("%d", &choice);
	switch (choice)
	{
	case 1: {
		printf("��������Ҫ�޸ĵ�������\n");
		scanf("%s", aname);
		while (strcmp(current->name, aname) != 0 && (!feof(fp)))
		{
			fscanf(fp, "%s %f", current->name, &current->score);
			while ((ch = getc(fp)) == ' ');//�Ե��ո񣬱����ж��ļ�ĩβ
			if (ch != ' '&&ch != EOF)
			{
				fseek(fp, -1L, SEEK_CUR);//��ָ�����һ�ֽڣ���ֹ����
			}
		}
		if (feof(fp))
			printf("���޴���\n");
		else
		{
			printf("%s\t%.2f\n", current->name, current->score);
			printf("�������޸ĺ�ĳɼ���\n");
			len = sizeof(current->score);
			fseek(fp, -len, SEEK_CUR);
			scanf("%f", &current->score);
			fseek(fp, 1L, SEEK_CUR);
			fprintf(fp, "%.2f", current->score);
			fseek(fp, -len, SEEK_CUR);
			fscanf(fp, "%f", &current->score);
			printf("%s\t%.2f\n", current->name, current->score);
		}

	}
			break;
	case 3:fclose(fp);
		break;
	case 4:exit(0);
	}
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
void goal3(struct stu*head)
{
	stu  *current;
	int a;
	for (current = head, a = 1; current != NULL; current = current->next, a++)
	{
		if (a == 1)
		{
			current->mark = ((current->mark) / 10) * 10 + 5;
		}
		else if (a == 2)
		{
			current->mark = ((current->mark) / 10) * 10 + 3;
		}
		else if (a == 3)
		{
			current->mark = ((current->mark) / 10) * 10 + 2;
		}
		else
		{
			current->mark = ((current->mark) / 10) * 10 + 0;
		}
	}
}
void goal5(struct stu*head)
{
	stu  *current;
	int a;
	for (current = head, a = 1; current != NULL; current = current->next, a++)
	{
		if (a == 1)
		{
			current->mark = ((current->mark) / 10) * 10 + 7;
		}
		else if (a == 2)
		{
			current->mark = ((current->mark) / 10) * 10 + 5;
		}
		else if (a == 3)
		{
			current->mark = ((current->mark) / 10) * 10 + 3;
		}
		else if (a == 4)
		{
			current->mark = ((current->mark) / 10) * 10 + 2;
		}
		else if (a == 4)
		{
			current->mark = ((current->mark) / 10) * 10 + 1;
		}
		else
		{
			current->mark = ((current->mark) / 10) * 10 + 0;
		}
	}
}
void chainfree(struct stu *head)
{
	stu *current;
	current = head;
	while (current != NULL)
	{
		head = current->next;
		free(current);
		current = head;

	}
}
void chaincheck(struct stu*head)
{
	stu *p;
	p = head;
	while (p != NULL)
	{
		printf("\n%s%s%s%s%.2f%d\n", p->name, p->sex, p->coll, p->item, p->score, p->mark);
		p = p->next;
	}
}