#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include "cjgl.h"
void adisplay(void);
void adisplay(void)
{
	printf("\t\t\t1、修改成绩\n");
	printf("\t\t\t2、删除成绩\n");
	printf("\t\t\t3、返回上一层\n");
	printf("\t\t\t4、退出程序\n");
	printf("请输入数字1-4以执行程序：\n");
}void alter(void)//修改成绩的函数
{
	adisplay();
	int choice, len;
	char aname[40], ch;
	FILE *fp;
	stu *current;
	current = NULL;
	current = (stu*)malloc(sizeof(stu));
	fp = fopen("成绩.txt", "r+");
	if (fp == NULL)
	{
		printf("文件打开错误！\n");
		exit(EXIT_FAILURE);
	}
	fscanf(fp, "%s%s%s%s%f", current->name, current->sex, current->coll, current->item, &current->score);
	scanf("%d", &choice);
	switch (choice)
	{
	case 1: {
		printf("请输入需要修改的姓名：\n");
		scanf("%s", aname);
		while (strcmp(current->name, aname) != 0 && (!feof(fp)))
		{
			fscanf(fp, "%s %f", current->name, &current->score);
			while ((ch = getc(fp)) == ' ');//吃掉空格，便于判断文件末尾
			if (ch != ' '&&ch != EOF)
			{
				fseek(fp, -1L, SEEK_CUR);//将指针回退一字节，防止乱码
			}
		}
		if (feof(fp))
			printf("查无此人\n");
		else
		{
			printf("%s\t%.2f\n", current->name, current->score);
			printf("请输入修改后的成绩：\n");
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