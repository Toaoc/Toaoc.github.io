#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include "cjgl.h"
void adisplay(void);
void adisplay(void)
{
	printf("\t\t\t1���޸ĳɼ�\n");
	printf("\t\t\t2��ɾ���ɼ�\n");
	printf("\t\t\t3��������һ��\n");
	printf("\t\t\t4���˳�����\n");
	printf("����������1-4��ִ�г���\n");
}void alter(void)//�޸ĳɼ��ĺ���
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