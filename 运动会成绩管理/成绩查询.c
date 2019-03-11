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
void sdisplay1(void)
{
	system("cls");
	printf("***********************运动会成绩管理系统*********************\n");
	printf("\t\t\t1.按校运会届数查询\n");
	printf("\t\t\t2.查询各学院历届校运会表现情况\n");
	printf("\t\t\t3.查询学生历届校运会表现情况\n");
	printf("\t\t\t4.返回上一层\n");
	printf("\t\t\t5.退出程序\n");
	printf("请输入数字1-5执行程序：\n");
}

void search(void)
{
	sdisplay1();
	int select;
	scanf("%d", &select);
	switch (select)
	{
	case 1:search2();
		break;
	case 2:
	{
		char colname[30];
		printf("请输入学院名：\n");
		scanf("%s", colname);
		seacol(colname);
		break;
	}
	case 3:
	{
		char stuname[40];
		printf("请输入学生姓名：\n");
		scanf("%s", stuname);
		seaname(stuname);
		break;
	}
	}
}
void sdisplay2(char tem[])
{
	system("cls");
	printf("\t\t\t1、%s届学院总分报表查询\n",tem);
	printf("\t\t\t2、%s届学院成绩查询\n",tem);
	printf("\t\t\t3、%s届个人成绩查询\n",tem);
	printf("\t\t\t4、%s届各项目成绩查询\n",tem);
	printf("\t\t\t5、%s届全部成绩\n",tem);
	printf("\t\t\t6、返回上一层\n");
	printf("\t\t\t7、退出程序\n");
	printf("注意：在本次程序运行中录入的成绩需重启后方可查询\n");
	printf("请输入数字1-7执行程序：\n");
}
void search2(void)
{
	FILE *fp;
	int a ;
	char ch;
	char sname[40], tem[15], fname[30], scoll[40], sitem[30];
	printf("请输入要查询的届数：\n");
	scanf("%s",tem);
	strcpy(fname, tem);
	strcat(fname, ".txt");
	sdisplay2(tem);
	int choice;
	scanf("%d", &choice);
	stu *current, *prev, *head;
	current = NULL;
	head = NULL;
	prev = NULL;
	fp = fopen(fname, "r+");
	if (fp == NULL)
	{
		printf("文件无法打开\n");
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
		while ((ch = getc(fp)) == ' ');//吃掉空格，便于判断文件末尾
		if (ch != ' '&&ch != EOF)
		{
			fseek(fp, -1L, SEEK_CUR);//将指针回退一字节，防止乱码
		}
	}
	current->next = NULL;
	//head=sort(head);
	switch (choice)
	{
	case 1:
	{
		char mcoll[30][30] = { 'a' };
		int tp[30] = { 0 };
		int nc = 0, ic;
		current = head;
		strcpy(mcoll[0], current->coll);
		//tp[0] = current->mark % 10;
		while (current != NULL)
		{
			for (ic = 0; ic < nc + 1; ic++)
			{
				if (strcmp(mcoll[ic], current->coll) != 0 && ic == nc)
				{
					strcpy(mcoll[nc + 1], current->coll);
					nc++;
				}
				else if (strcmp(mcoll[ic], current->coll) == 0)
				{
					tp[ic] = tp[ic] + current->mark % 10;
					break;
				}
			}
			current = current->next;
		}
		for (ic = 0; ic < nc + 1; ic++)
		{
			printf("%s\t%d\n", mcoll[ic], tp[ic]);
		}
		a = 1;
		printf("返回上一层请按1\n退出程序请按2\n");
		scanf("%d", &a);
		if (a == 1)
			break;
		if (a == 2)
			exit(0);
	}
	case 2://按学院进行查询
	{
		a = 1;
		while (a == 1)
		{
			printf("请输入要查询的学院名称：\n");
			s_gets(scoll, 40);
			current = head;
			while (current != NULL)
			{
				if (strcmp(current->coll, scoll) == 0)
				{
					printf("%s\t%s\t%s\t%s\t%.2f\n", current->name, current->sex, current->coll, current->item, current->score);
					a++;
				}
				current = current->next;
			}
			if (a == 1)
				printf("没有此学院，请检查后重新输入\n");
			printf("继续查询请按1\n返回上一层请按2\n退出程序请按3\n");
			scanf("%d", &a);
			if (a == 3)
				exit(0);
		}
		break;
	}
	case 3: //按姓名进行查询
	{	
		a = 1;
		while (a == 1)
		{
			printf("请输入姓名：\n");
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
				printf("查无此人\n");
			printf("继续查询请按1\n返回上一层请按2\n退出程序请按3\n");
			scanf("%d", &a);
			if (a == 3)
				exit(0);
		}
	}
	break;
	case 4:
	{
		a = 1;
		while (a == 1)
		{
			printf("请输入项目名称：\n");
			s_gets(sitem, 30);
			current = head;
			while (current != NULL)
			{
				if (strcmp(current->item,sitem) == 0)
				{
					printf("%s\t%s\t%s\t%s\t%.2f\n", current->name, current->sex, current->coll, current->item, current->score);
					a++;
				}
				current = current->next;
			}
			if (a == 1)
				printf("没有此项目，请检查后重新输入！\n");
			printf("继续查询请按1\n返回上一层请按2\n退出程序请按3\n");
			scanf("%d", &a);
			if (a == 3)
				exit(0);
		}
	}
	break;
	case 5://输出该届全部成绩
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
		a = 1;
		printf("返回上一层请按1\n退出程序请按2\n");
		scanf("%d", &a);
		if (a == 2)
			exit(0);
	}
	case 8:exit(0);
	}
	fclose(fp);
}
void seacol(char *colname)
{

	long Handle;
	FILE *fp;
	char scname[40], scsex[5], scitem[30], sccol[40], str[20];
	float scsco;
	int  scmark;
	struct _finddata_t FileInfo;

	if ((Handle = _findfirst("*.txt", &FileInfo)) == -1L)

		printf("暂无运动会成绩，请进行录入\n");

	else

	{

		//printf("%s\n", FileInfo.name);
		strcpy(str, FileInfo.name);
		killdot(str);
		printf("%s:\n", str);
		fp = fopen(FileInfo.name, "r + ");
		while (!feof(fp))
		{
			if (fscanf(fp, "%s%s%s%s%f%d", scname, scsex, sccol, scitem, &scsco, &scmark) != 6)
				break;
			if (strcmp(sccol, colname) == 0)
				printf("%s\t%s\t%s\t%s\t%.2f\n", scname, scsex, sccol, scitem, scsco);
		}
		fclose(fp);
		//printf('\n');
		while (_findnext(Handle, &FileInfo) == 0)
		{
			//printf("%s\n", FileInfo.name);
			strcpy(str, FileInfo.name);
			killdot(str);
			printf("%s:\n", str);
			fp = fopen(FileInfo.name, "r+");
			while (!feof(fp))
			{
				if (fscanf(fp, "%s%s%s%s%f%d", scname, scsex, sccol, scitem, &scsco, &scmark) != 6)
					break;
				if (strcmp(sccol, colname) == 0)
					printf("%s\t%s\t%s\t%s\t%.2f\n", scname, scsex, sccol, scitem, scsco);
			}
			fclose(fp);
			//printf('\n');
		}
		_findclose(Handle);

	}
}
void seaname(char *stuname)
{

	long Handle;
	FILE *fp;
	char scname[40], scsex[5], scitem[30], sccol[40], str[20];
	float scsco;
	int  scmark;
	struct _finddata_t FileInfo;

	if ((Handle = _findfirst("*.txt", &FileInfo)) == -1L)

		printf("暂无运动会成绩，请进行录入\n");

	else

	{

		//printf("%s\n", FileInfo.name);
		strcpy(str, FileInfo.name);
		killdot(str);
		//printf("%s:\n", str);
		fp = fopen(FileInfo.name, "r + ");
		while (!feof(fp))
		{
			if (fscanf(fp, "%s%s%s%s%f%d", scname, scsex, sccol, scitem, &scsco, &scmark) != 6)
				break;
			if (strcmp(scname, stuname) == 0)
			{
				printf("%s:\n", str);
				printf("%s\t%s\t%s\t%s\t%.2f\n", scname, scsex, sccol, scitem, scsco);
			}
		}
		fclose(fp);
		//printf('\n');
		while (_findnext(Handle, &FileInfo) == 0)
		{
			//printf("%s\n", FileInfo.name);
			strcpy(str, FileInfo.name);
			killdot(str);
			//printf("%s:\n", str);
			fp = fopen(FileInfo.name, "r+");
			while (!feof(fp))
			{
				if (fscanf(fp, "%s%s%s%s%f%d", scname, scsex, sccol, scitem, &scsco, &scmark) != 6)
					break;
				if (strcmp(scname, stuname) == 0)
				{
					printf("%s:\n", str);
					printf("%s\t%s\t%s\t%s\t%.2f\n", scname, scsex, sccol, scitem, scsco);
				}
			}
			fclose(fp);
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