#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include "cjgl.h"
void ensex(char *witem,char *wsex);//���ڴ���Ŀ��¼���Ա�
void singlewrite(char*fname);//������Ŀ¼��
void teamwrite(char*fname);//������Ŀ¼��
int get2(char *str);//�����ж�¼�루ͨ������ֵ��
void enter(void)
{
	char fname[30], ch;//�ļ���������ݣ�
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
		{
			while ((ch = getchar() != '\n') && ch != EOF);
			printf("����������������룺\n");
		}
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
	FILE *fp, *nf, *ff;
	stu * head, *prev, *current;
	char  wname[40], wsex[5], wcoll[30], witem[20], fname1[20], ch, gitem[30], gname[20];//��w�Ķ���������ʱ�洢���ݣ���ֱֹ�Ӷ�������в���ʱ��������
	int a, b, wmark, i, j, k, n, defen[10], gmark, fbug, fbug2;//a,b�������ɱ�����ǰ��λ��a��������Σ�b��������ʽ
	float wscore;
	head = NULL;
	prev = NULL;
	current = NULL;
	fbug = 0;
	/*printf("�������˶��������\n");
	scanf("%s", fname);*/
	strcpy(gname, fname);
	strcat(gname, "score.txt");
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
			printf("������Ա���������룺\n");
	}
	fbug2 = 0;
	//getchar();
	while (1)
	{
		rename(fname1, fname);
		rename(fname, fname1);//��ԭ�ļ���Ϊc.txt,ʹ���Ϊ�м��ļ�
		fp = fopen(fname1, "a+");
		if (fp == NULL)
		{
			printf("�ļ��򿪴���\n");
			exit(EXIT_FAILURE);
		}
		ff = fopen(gname, "a+");
		strcpy(gitem, "a");
		while (!feof(ff))
		{
			if (fscanf(ff, "%s", gitem) != 1)
			{ 
				break;
			}
			if (strcmp(gitem, witem) != 0&&!feof(ff))
			{
				for (i = 0; i < 10; i++)
				{
					fscanf(ff, "%d", &defen[i]);
				}
				fscanf(ff, "%d", &gmark);
			}
			else if (strcmp(gitem, witem) == 0)
			{
				for (i = 0; i < 10; i++)
				{
					fscanf(ff, "%d", &defen[i]);
				}
				fscanf(ff, "%d", &gmark);
				break;
			}
		}
		if (strcmp(gitem, witem) != 0)
		{
			printf("���������Ŀ�Ļ����Σ�\n");
			printf("1.ȡǰ3��\n2.ȡǰ5��\n3.�Զ���\n");
			while (scanf("%d", &a) != 1 )
			{
				while ((ch = getchar() != '\n') && ch != EOF);
				printf("�����������������Ҫȡ������\n");
			}
			while (a < 1 || a > 3)
			{
				printf("�����������������Ҫȡ������\n");
				while (scanf("%d", &a) != 1)
				{
					while ((ch = getchar() != '\n') && ch != EOF);
					printf("�����������������Ҫȡ������\n");
				}
			}
			switch (a)
			{
			case 1:
			{
				a = 3;
				defen[0] = 5;
				defen[1] = 3;
				defen[2] = 2;
				for (i = 3; i < 10; i++)
					defen[i] = 0;
				break;
			}
			case 2:
			{
				a = 5;
				defen[0] = 7;
				defen[1] = 5;
				defen[2] = 3;
				defen[3] = 2;
				defen[4] = 1;
				for (i = 5; i < 10; i++)
					defen[i] = 0;
				break;
			}
			case 3:
			{
				printf("������Ҫȡ������(1-10)��\n");
				while (scanf("%d", &a) != 1 )
				{
					while ((ch = getchar() != '\n') && ch != EOF);
					printf("�����������������Ҫȡ������\n");
				} 
				while (a < 1 || a > 10)
				{
					printf("�����������������Ҫȡ������\n");
					while (scanf("%d", &a) != 1)
					{
						while ((ch = getchar() != '\n') && ch != EOF);
						printf("�����������������Ҫȡ������\n");
					}

				}
				for (i = 1; i < a + 1; i++)
				{
					printf("�������%d���ɻ�õĵķ�����\n", i);
					while (scanf("%d", &defen[i - 1]) != 1)
					{
						while ((ch = getchar() != '\n') && ch != EOF);
						printf("������������������%d���ɻ�õĵķ�����\n", i);
					}
				}
				for (i = i - 1; i < 10; i++)
				{
					defen[i] = 0;
				}
				break;
			}
			default:printf("�����bug�����ͼ����ϵ������Ա\n"); exit(1);
			}

			printf("����Ŀ�ĺóɼ�Ϊ����ֵ���ǵ���ֵ��\n1������ֵ\n2������ֵ\n");
			while ((i = scanf("%d", &b)) != 1 || (b != 1 && b != 2))
			{
				if (1 != i)
				{
					while ((ch = getchar() != '\n') && ch != EOF);
				}
				printf("�����������������\n");
			}
			gmark = a * 100 + b * 10;
			fprintf(ff, " %s ", witem);
			for (i = 0; i < 10; i++)
			{
				fprintf(ff, " %d ", defen[i]);
			}
			fprintf(ff, " %d ", gmark);
			fclose(ff);
			fbug = 0;
		}
		else
		{
			fbug = fbug + fbug2;
			fbug++;
		}
		printf("\n������%s�����ߵ����������н�������Ŀ���룩��\n", witem);
		//getchar();//���ڶ�ȡ�������������Ļ��з�����ֹ�жϳ���
		if (fbug < 2)
			getchar();
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
			printf("������%s����ѧԺ��\n", wname);
			scanf("%s", current->coll);
			printf("������%s�ĳɼ���\n", wname);
			while (scanf("%f", &current->score) != 1)
			{
				while ((ch = getchar() != '\n') && ch != EOF);
				printf("�����������������\n");
			}
			current->mark = gmark;//���ɱ����ǰ��λ
			printf("¼��ɹ���\n");
			prev = current;
			printf("������%s��һ�����ߵ����������н�������Ŀ¼�룩��\n", witem);
			getchar();
		}
		if (head == NULL)
			break;
		rewind(fp);//��ָ��ص�����ͷ��
		while (!feof(fp))//���ļ��ж�ȡͬ��Ŀ����������
		{
			
			if (fscanf(fp, "%s%s%s%s%f%d", wname, wsex, wcoll, witem, &wscore, &wmark) != 6)
				break;
			printf("%s\n", wname);
			if (strcmp(current->item, witem) == 0)
			{
				printf("%s\n", wname);
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
		}
		printf("%s\n", current->name);
		current->next = NULL;
		if ((head->mark % 100) / 10 == 1)//�������������������
		{
			head = maxsort(head);	
			goal(gname,head);
		}
		else
		{
			head = minsort(head);
			goal(gname, head);
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
			{
				fbug2 = 1;
				break;
			}
			else
				printf("������Ա���������룺\n");
		}

	}

}
void teamwrite(char*fname)//������Ŀ¼��
{
	FILE *fp, *nf ,*ff;
	stu * head, *prev, *current;
	char  wname[40], wsex[5], wcoll[30], witem[20], fname1[20], ch, gname[20],gitem[30];//��w�Ķ���������ʱ�����
	int a, b, wmark, i, j, k, n, c, gmark, defen[10], fbug, fbug2;
	float wscore;
	head = NULL;
	prev = NULL;
	current = NULL;
	fbug = 0;
	strcpy(gname, fname);
	strcat(gname, "score.txt");
	strcpy(fname1, fname);
	strcat(fname1, "c.txt");
	strcat(fname, ".txt");
	for (k = 0; k != -1; k++)//��ȡ��Ŀ���ж��Ա�
	{
		printf("������������Ŀ����(\033[1;31;47m���Ա�\033[0m����\033[1;31;47m����\033[0m����\033[1;31;47mŮ��\033[0m���򣩣�\n");
		scanf("%s", witem);
		ensex(witem, wsex);
		if (strcmp(wsex, "��") == 0 || strcmp(wsex, "Ů") == 0)
			break;
		else
			printf("������Ա���������룺\n");
	}
	fbug2 = 0;
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
		ff = fopen(gname, "a+");
		strcpy(gitem, "a");
		while (!feof(ff))
		{
			if (fscanf(ff, "%s", gitem) != 1)
			{
				break;
			}
			if (strcmp(gitem, witem) != 0 && !feof(ff))
			{
				for (i = 0; i < 10; i++)
				{
					fscanf(ff, "%d", &defen[i]);
				}
				fscanf(ff, "%d", &gmark);
			}
			else if (strcmp(gitem, witem) == 0)
			{
				for (i = 0; i < 10; i++)
				{
					fscanf(ff, "%d", &defen[i]);
				}
				fscanf(ff, "%d", &gmark);
				break;
			}
		}
		if (strcmp(gitem, witem) != 0)
		{
			printf("���������Ŀ�Ļ����Σ�\n");
			printf("1.ȡǰ3��\n2.ȡǰ5��\n3.�Զ���\n");
			while ((i = scanf("%d", &a)) != 1 || a < 1 || a > 3)
			{
				if(i!=1)
					while ((ch = getchar() != '\n') && ch != EOF);
				printf("�����������������Ҫȡ������\n");
			}
			switch (a)
			{
			case 1:
			{
				a = 3;
				defen[0] = 5;
				defen[1] = 3;
				defen[2] = 2;
				for (i = 3; i < 10; i++)
					defen[i] = 0;
				break;
			}
			case 2:
			{
				a = 5;
				defen[0] = 7;
				defen[1] = 5;
				defen[2] = 3;
				defen[3] = 2;
				defen[4] = 1;
				for (i = 5; i < 10; i++)
					defen[i] = 0;
				break;
			}
			case 3:
			{
				printf("������Ҫȡ������(1-10)��\n");
				while ((i = scanf("%d", &a) != 1) || a < 1 || a > 10)
				{
					if(i!=1)
						while ((ch = getchar() != '\n') && ch != EOF);
					printf("�����������������Ҫȡ������\n");
				}
				for (i = 1; i < a + 1; i++)
				{
					printf("�������%d���ɻ�õĵķ�����\n", i);
					scanf("%d", &defen[i - 1]);
				}
				for (i = i - 1; i < 10; i++)
				{
					defen[i] = 0;
				}
				break;
			}
			default:printf("�����bug�����ͼ���翪����Ա\n"); exit(1);
			}
			printf("%s��1-%d���Ƿ���ֵ�ɼ�ͳһ������\n1����\n2����\n", witem, a);
			while ((i = scanf("%d", &c)) != 1 || (c != 1 && c != 2))
			{
				if(i!=1)
					while ((ch = getchar() != '\n') && ch != EOF);
				printf("�����������������\n");
			}
			if (1 == c)
				b = c + 1;
			else
				b = 5;//��ֵΪ5���ڶ�����漸�����
			if (2 == b)
			{
				printf("%s�ĺóɼ�Ϊ����ֵ���ǵ���ֵ��\n1������ֵ\n2������ֵ\n", witem);
				while ((i=scanf("%d", &c)) != 1 || (c != 1 && c != 2))
				{
					if(i!=1)
						while ((ch = getchar() != '\n') && ch != EOF);
					printf("�����������������\n");
				}
				b = b + c;
			}
			gmark = a * 100 + b * 10;
			fprintf(ff, " %s ", witem);
			for (i = 0; i < 10; i++)
			{
				fprintf(ff, " %d ", defen[i]);
			}
			fprintf(ff, " %d ", gmark);
			fclose(ff);
			fbug = 0;
		}
		else
		{
			a = gmark / 100;
			b = (gmark % 100) / 10;
			fbug = fbug + fbug2;
			fbug++;
		}
		printf("������%s����ѧԺ�����ƣ�\n", witem);
		if(fbug < 2)
			getchar();
		while (s_gets(wcoll, 45) != NULL && wcoll[0] != '\0')
		{
			if (3 == b || 4 == b)//3Ϊ�Ӵ�С�ţ�4Ϊ��С������
			{
				printf("������%s�ĳɼ���\n", wcoll);
				while (scanf("%f", &wscore) != 1)
				{
					while ((ch = getchar() != '\n') && ch != EOF);
					printf("�����������������\n");
				}
				//scanf("%f", &wscore);
			}
			else
			{
				printf("������%s��õ����Σ�\n", wcoll);
				while (scanf("%f", &wscore) != 1)
				{
					while ((ch = getchar() != '\n') && ch != EOF);
					printf("�����������������\n");
				}
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
		if (head == NULL)
			break;
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
			goal(gname, head);
		}
		else
		{
			head = minsort(head);
			goal(gname, head);

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
		printf("��������һҪ¼�����Ŀ(\033[1;31;47m���Ա�\033[0m����\033[1;31;47m����\033[0m����\033[1;31;47mŮ��\033[0m���򣩣����н���¼�룺\n");
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
			{
				fbug2 = 1;
				break;
			}
			else
				printf("������Ա���������룺\n");
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