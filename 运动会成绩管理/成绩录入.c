#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include "cjgl.h"
void wdisplay(void);
void ensex(char *witem,char *wsex);//���ڴ���Ŀ��¼���Ա�
void singlewrite(char*fname);//������Ŀ¼��
void teamwrite(char*fname);//������Ŀ¼��
int get2(char *str);//�����ж�¼�루ͨ������ֵ��
void enter(void)
{
	char fname[30];//�ļ���������ݣ�
	int choice;//���ڼ�¼�û���ѡ��
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
		while (scanf("%d", &choice) != 1)//�ж�������Ƿ���������
			printf("����������������룺\n");
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
	for (i = 0; i != 2; i++)//����Ŀ�н�ȡ�����ֽ���Ϊ�Ա�
		wsex[i] = witem[i];
	wsex[i] = '\0';
	printf("%s\t%s\n", witem, wsex);
}
void singlewrite(char *fname)
{
	FILE *fp, *nf;
	stu * head, *prev, *current;
	char  wname[40], wsex[5], wcoll[30], witem[20], fname1[20], ch, rname[40][30] = { 'a' };//��w�Ķ���������ʱ�洢���ݣ���ֱֹ�Ӷ�������в���ʱ��������
	int a, b, wmark, i, j, k, n;//a,b�������ɱ�����ǰ��λ��a��������Σ�b��������ʽ
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
	for (k = 0;k!=-1; k++)//ֻ��������Ա����Ŀ����break
	{
		printf("��������Ҫ¼�����Ŀ(\033[1;31;47m���Ա� \033[0m����\033[1;31;47m����\033[0m��Զ��\033[1;31;47mŮ��\033[0m���ߣ���\n");
		scanf("%s", witem);
		ensex(witem, wsex);//��ȡ�Ա�
		if (strcmp(wsex, "��") == 0 || strcmp(wsex, "Ů") == 0)
			break;
		else
			printf("������Ŀ�Ƿ�����Ա���������룺\n");
	}
	while (1)
	{
		rename(fname1, fname);
		rename(fname, fname1);//��ԭ�ļ���Ϊc.txt,ʹ���Ϊ�м��ļ�
		fp = fopen(fname1, "r");
		if (fp == NULL)
		{
			printf("�ļ��򿪴���\n");
			exit(EXIT_FAILURE);
		}
		printf("���������Ŀ�Ļ����Σ�\n");
		while (scanf("%d", &a) != 1||(a != 3 && a != 5))
			printf("�������������Ҫȡ������\n");
		printf("����Ŀ�ǵĺóɼ�Ϊ����ֵ���ǵ���ֵ��\n1������ֵ\n2������ֵ\n");
		while (scanf("%d", &b) != 1 || (b != 1 && b != 2))
			printf("�����������������\n");
		printf("\n������%s�����ߵ����������н�������Ŀ���룩��\n", witem);
		getchar();//���ڶ�ȡ�������������Ļ��з�����ֹ�жϳ���
		while (s_gets(wname, 45) != NULL && wname[0] != '\0')//�ж��û�������
		{
			current = (stu*)malloc(sizeof(stu));
			if (head == NULL)
				head = current;
			else
				prev->next = current;
			strcpy(current->name, wname);//���û������¼��������
			strcpy(current->item, witem);
			strcpy(current->sex, wsex);
			printf("%s\n", current->sex);
			/*printf("������%s���Ա�\n", wname);
			scanf("%s", current->sex);*/
			printf("������%s����ѧԺ��\n", wname);
			scanf("%s", current->coll);
			printf("������%s�ĳɼ���\n", wname);
			while (scanf("%f", &current->score) != 1)
				printf("�����������������\n");
			current->mark = 100 * a + 10 * b;//���ɱ����ǰ��λ
			printf("¼��ɹ���\n");
			prev = current;
			printf("������%s��һ�����ߵ����������н�������Ŀ¼�룩��\n", witem);
		}

		rewind(fp);//��ָ��ص�����ͷ��
		fscanf(fp, "%s%s%s%s%f%d", wname, wsex, wcoll, witem, &wscore, &wmark);
		i = 0;
		while (!feof(fp))//���ļ��ж�ȡͬ��Ŀ����������
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
		if ((head->mark % 100) / 10 == 1)//�������������������
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
		for (current = head; current != NULL; current = current->next)//�������������д�뵽���ļ���
		{
			fprintf(nf, " %s %s %s %s %.2f %d ", current->name, current->sex, current->coll, current->item, current->score, current->mark);
		}
		rewind(fp);//���ļ�ָ��ص���ʼ��ȡ��������
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
				fprintf(nf, " %s %s %s %s %.2f %d ", wname, wsex, wcoll, witem, wscore, wmark);//����������д�뵽���ļ���
				fflush(fp);
			}
			while ((ch = getc(fp)) == ' ');//�Ե��ո񣬱����ж��ļ�ĩβ
			if (ch != ' '&&ch != EOF)
			{
				fseek(fp, -1L, SEEK_CUR);//��ָ�����һ�ֽڣ���ֹ����
			}
		}
		chainfree(head);//�ͷ�����
		head = NULL;
		fclose(fp);
		fclose(nf);
		remove(fname1);//���м��ļ�ȥ��
		printf("��������Ҫ¼�����Ŀ(\033[1;31;47m���Ա�\033[0m����\033[1;31;47m����\033[0m��Զ��\033[1;31;47mŮ��\033[0m���ߣ������н������룺\n");
		n = get2(witem);
		if (n == 0)//n=0����ʾ�û�ֱ�Ӱ����˻س���
			break;
		for (k = 0;; k++)//�жϲ���ȡ�Ա�
		{
			if (k > 0)
			{
				printf("��������Ҫ¼�����Ŀ(\033[1;31;47m���Ա�\033[0m����\033[1;31;47m����\033[0m��Զ��\033[1;31;47mŮ��\033[0m���ߣ���\n");
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
void teamwrite(char*fname)//������Ŀ¼��
{
	FILE *fp, *nf;
	stu * head, *prev, *current;
	char  wname[40], wsex[5], wcoll[30], witem[20], fname1[20], ch, rname[40][30] = { 'a' };//��w�Ķ���������ʱ�����
	int a, b, wmark, i, j, k, n, c;
	float wscore;
	head = NULL;
	prev = NULL;
	current = NULL;
	strcpy(fname1, fname);
	strcat(fname1, "c.txt");
	strcat(fname, ".txt");
	for (k = 0; k != -1; k++)//��ȡ��Ŀ���ж��Ա�
	{
		printf("��������Ҫ¼���������Ŀ(\033[1;31;47m���Ա�\033[0m����\033[1;31;47m����\033[0m����\033[1;31;47mŮ��\033[0m���򣩣�\n");
		scanf("%s", witem);
		ensex(witem, wsex);
		if (strcmp(wsex, "��") == 0 || strcmp(wsex, "Ů") == 0)
			break;
		else
			printf("������Ŀ�Ƿ�����Ա���������룺\n");
	}
	while (1)
	{
		rename(fname1, fname);
		rename(fname, fname1);//��ԭ�ļ��ĳ��м��ļ�
		fp = fopen(fname1, "r");
		if (fp == NULL)
		{
			printf("�ļ��򿪴���\n");
			exit(EXIT_FAILURE);
		}
		printf("������%s�Ļ����Σ�\n", witem);
		while (scanf("%d", &a) != 1 || (a != 3 && a != 5))
			printf("�������������Ҫȡ������\n");
		printf("%s��1-%d���Ƿ���ֵ�ɼ�ͳһ������\n1����\n2����\n", witem, a);
		while (scanf("%d", &c) != 1 || (c != 1 && c != 2))
			printf("�����������������\n");
		if (1 == c)
			b = c + 1;
		else
			b = 5;//��ֵΪ5���ڶ�����漸�����
		if (2 == b)
		{
			printf("%s�ĺóɼ�Ϊ����ֵ���ǵ���ֵ��\n1������ֵ\n2������ֵ\n", witem);
			while (scanf("%d", &c) != 1 || (c != 1 && c != 2))
				printf("�����������������\n");
			b = b + c;
		}
		printf("������%s����ѧԺ�����ƣ�\n", witem);
		getchar();
		while (s_gets(wcoll, 45) != NULL && wcoll[0] != '\0')
		{
			if (3 == b || 4 == b)//3Ϊ�Ӵ�С�ţ�4Ϊ��С������
			{
				printf("������%s�ĳɼ���\n", wcoll);
				while (scanf("%f", &wscore) != 1)
					printf("�����������������\n");
				//scanf("%f", &wscore);
			}
			else
			{
				printf("������%s��õ����Σ�\n", wcoll);
				while (scanf("%f", &wscore) != 1)
					printf("�����������������\n");
				b = 4;//��b�Ļ�Ϊ4��4��Ϊ��С������
			}
			printf("������%s��ѡ�֣�\n", wcoll);
			getchar();//���ڶ�ȡ����Ļ��з��������ж�
			while (s_gets(wname,45) != NULL && wname[0] != '\0')
			{
				current = (stu*)malloc(sizeof(stu));
				if (head == NULL)
					head = current;
				else
					prev->next = current;
				strcpy(current->coll, wcoll);//����ʱ��ȡ��д�뵽������
				strcpy(current->item, witem);
				strcpy(current->sex, wsex);
				strcpy(current->name, wname);
				current->score = wscore;
				current->mark = 100 * a + 10 * b;
				prev = current;
				printf("������%s��һѡ�ֵ����������н������룩��\n", wcoll);
			}
			printf("\n������%s��һ����ѧԺ�����ƣ����н�������Ŀ¼�룩��\n", witem);
		}

		rewind(fp);
		fscanf(fp, "%s%s%s%s%f%d", wname, wsex, wcoll, witem, &wscore, &wmark);//�ȳ��Զ�ȡ�������ж��ļ�ĩβ
		i = 0;
		while (!feof(fp))//���ļ��ж�ȡͬһ����Ŀ�ĵ������������������
		{
			if (!feof(fp) && i != 0)//i!=0���ڷ�ֹ�ļ���һ�����ظ���ȡ
				fscanf(fp, "%s%s%s%s%f%d", wname, wsex, wcoll, witem, &wscore, &wmark);
			i++;
			if (strcmp(current->item, witem) == 0)
			{
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
		}
		current->next = NULL;

		if ((head->mark % 100) / 10 == 1 || (head->mark % 100) / 10 == 3)//���򡢸���
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

		nf = fopen(fname, "w");//���ļ�д�뵽���ļ���
		for (current = head; current != NULL; current = current->next)
		{
			fprintf(nf, " %s %s %s %s %.2f %d ", current->name, current->sex, current->coll, current->item, current->score, current->mark);

		}
		rewind(fp);//�ص�ָ�룬��ȡ��¼�����Ŀ
		while (!feof(fp))
		{
			if (fscanf(fp, "%s%s%s%s%f%d", wname, wsex, wcoll, witem, &wscore, &wmark) != 6)
				break;
			for (current = head, j = 0; (current != NULL) && (!feof(fp)); current = current->next)
			{
				if (strcmp(current->name, wname) == 0)
					j++;//j���ڼ�¼�Ƿ���������
			}
			if (j == 0)
			{
				fprintf(nf, " %s %s %s %s %.2f %d ", wname, wsex, wcoll, witem, wscore, wmark);
				fflush(fp);
			}
			while ((ch = getc(fp)) == ' ');//�Ե��ո񣬱����ж��ļ�ĩβ
			if (ch != ' '&&ch != EOF)
			{
				fseek(fp, -1L, SEEK_CUR);//��ָ�����һ�ֽڣ���ֹ����
			}
		}
		chainfree(head);//�ͷ�����
		head = NULL;
		fclose(fp);
		fclose(nf);
		remove(fname1);//���м��ļ��Ƴ�
		printf("��������һҪ¼�����Ŀ(���н���¼��)��\n");
		n = get2(witem);
		if (n == 0)
			break;
		for (k = 0;; k++)
		{
			if (k > 0)
			{
				printf("��������Ҫ¼���������Ŀ(\033[1;31;47m���Ա�\033[0m����\033[1;31;47m����\033[0m����\033[1;31;47mŮ��\033[0m���򣩣�\n");
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
int get2(char *str)//������Ļ��кŻ���'\0',������'\0'����λ��
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