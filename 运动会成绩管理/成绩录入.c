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
		printf("请输入要录入的年份：\n");
		scanf("%s", fname);
		system("cls");
		printf("\t\t\t1、个人项目录入\n");
		printf("\t\t\t2、团体项目录入\n");
		printf("\t\t\t3、返回上一层\n");
		printf("\t\t\t4、退出程序\n");
		printf("请输入数字1-4执行程序：");
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
		default:printf("请输入数字1-4执行程序：");
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
	//printf("注意！录入时请不要中途退出！！\n");
	FILE *fp, *nf;
	stu * head, *prev, *current;
	char  wname[40], wsex[5], wcoll[30], witem[20], fname1[20], ch, rname[40][30] = { 'a' };
	int a, b, wmark, i, j, k, n;
	float wscore;
	head = NULL;
	prev = NULL;
	current = NULL;
	/*printf("请输入运动会届数：\n");
	scanf("%s", fname);*/
	strcpy(fname1, fname);
	strcat(fname1, "c.txt");
	strcat(fname, ".txt");
	//rename(fname, fname1);
	/*fp = fopen(fname, "a+");
	if (fp == NULL)
	{
		printf("文件打开错误！\n");
		exit(EXIT_FAILURE);
	}*/
	for (k = 0;k!=-1; k++)
	{
		printf("请输入所要录入的项目(\033[1;31;47m带性别 \033[0m，如男子跳远、女子跳高）：\n");
		scanf("%s", witem);
		ensex(witem, wsex);
		if (strcmp(wsex, "男") == 0 || strcmp(wsex, "女") == 0)
			break;
		else
			printf("请检查项目是否带上性别后重新输入：\n");
	}
	while (1)
	{
		rename(fname1, fname);//防止因之前用户不规范退出使临时文件名称名未修改而造成的数据丢失
		rename(fname, fname1);
		fp = fopen(fname1, "a+");
		if (fp == NULL)
		{
			printf("文件打开错误！\n");
			exit(EXIT_FAILURE);
		}
		printf("请输入该项目的获奖名次：\n");
		scanf("%d", &a);
		printf("该项目是的好成绩为高数值还是低数值：\n1、高数值\n2、低数值\n");
		scanf("%d", &b);
		printf("\n请输入%s参赛者的姓名（空行结束该项目输入）：\n", witem);
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
			/*printf("请输入%s的性别：\n", wname);
			scanf("%s", current->sex);*/
			printf("请输入%s所属学院：\n", wname);
			scanf("%s", current->coll);
			printf("请输入%s的成绩：\n", wname);
			scanf("%f", &current->score);
			current->mark = 100 * a + 10 * b;
			printf("录入成功！\n");
			prev = current;
			printf("请输入%s另一参赛者的姓名（空行结束该项目录入）：\n", witem);
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
			while ((ch = getc(fp)) == ' ');//吃掉空格，便于判断文件末尾
			if (ch != ' '&&ch != EOF)
			{
				fseek(fp, -1L, SEEK_CUR);//将指针回退一字节，防止乱码
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
			while ((ch = getc(fp)) == ' ');//吃掉空格，便于判断文件末尾
			if (ch != ' '&&ch != EOF)
			{
				fseek(fp, -1L, SEEK_CUR);//将指针回退一字节，防止乱码
			}
		}
		chainfree(head);
		head = NULL;
		fclose(fp);
		fclose(nf);
		remove(fname1);
		printf("请输入所要录入的项目(带性别，如男子跳远、女子跳高）：\n");
		n = get2(witem);
		if (n == 0)
			break;
		for (k = 0;; k++)
		{
			if (k > 0)
			{
				printf("请输入所要录入的项目(带性别，如男子跳远、女子跳高）：\n");
				scanf("%s", witem);
			}
			ensex(witem, wsex);
			if (strcmp(wsex, "男") != 0 || strcmp(wsex, "女") != 0)
				break;
			else
				printf("请检查项目是否带上性别后重新输入：\n");
		}

	}

}
void teamwrite(char*fname)
{
	//system("cls");
	//printf("注意！录入时请不要中途退出！！\n");
	FILE *fp, *nf;
	stu * head, *prev, *current;
	char  wname[40], wsex[5], wcoll[30], witem[20], fname1[20], ch, rname[40][30] = { 'a' };
	int a, b, wmark, i, j, k, n, c;
	float wscore;
	head = NULL;
	prev = NULL;
	current = NULL;
	//printf("请输入运动会届数：\n");
	//scanf("%s", fname);
	strcpy(fname1, fname);
	strcat(fname1, "c.txt");
	strcat(fname, ".txt");
	//rename(fname, fname1);
	/*fp = fopen(fname, "a+");
	if (fp == NULL)
	{
		printf("文件打开错误！\n");
		exit(EXIT_FAILURE);
	}*/
	for (k = 0; k != -1; k++)
	{
		printf("请输入所要录入的团体项目(带性别，如男子篮球、女子足球）：\n");
		scanf("%s", witem);
		ensex(witem, wsex);
		if (strcmp(wsex, "男") == 0 || strcmp(wsex, "女") == 0)
			break;
		else
			printf("请检查项目是否带上性别后重新输入：\n");
	}
	while (1)
	{
		rename(fname1, fname);//防止因之前用户不规范退出使临时文件名称名未修改而造成的数据丢失
		rename(fname, fname1);
		fp = fopen(fname1, "a+");
		if (fp == NULL)
		{
			printf("文件打开错误！\n");
			exit(EXIT_FAILURE);
		}
		printf("请输入%s的获奖名次：\n", witem);
		scanf("%d", &a);
		printf("%s的1-%d名是否按数值成绩统一排名：\n1、是\n2、否\n", witem, a);
		scanf("%d", &c);
		if (1 == c)
			b = c + 1;
		else
			b = 5;
		if (2 == b)
		{
			printf("%s的好成绩为高数值还是低数值：\n1、高数值\n2、低数值\n", witem);
			scanf("%d", &c);
			b = b + c;
		}
		//printf("\n请输入%s参赛者的姓名（空行结束该项目输入）：\n", witem);
		printf("请输入%s参赛学院的名称：\n", witem);
		getchar();
		while (s_gets(wcoll, 45) != NULL && wcoll[0] != '\0')
		{
			if (3 == b || 4 == b)
			{
				printf("请输入%s的成绩：\n", wcoll);
				scanf("%f", &wscore);
			}
			else
			{
				printf("请输入%s获得的名次：\n", wcoll);
				scanf("%f", &wscore);
				b = 4;
			}
			printf("请输入%s的选手：\n", wcoll);
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
				/*printf("请输入%s的性别：\n", wname);
				scanf("%s", current->sex);*/
				/*printf("请输入%s的选手：\n", wcoll);
				scanf("%s", current->coll);*/
				/*printf("请输入%s的成绩：\n", wcoll);
				scanf("%f", &current->score);*/
				current->mark = 100 * a + 10 * b;
				//printf("录入成功！\n");
				prev = current;
				printf("请输入%s另一选手的姓名（空行结束输入）：\n", wcoll);
			}
			printf("\n请输入%s另一参赛学院的名称（空行结束该项目录入）：\n", witem);
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
			while ((ch = getc(fp)) == ' ');//吃掉空格，便于判断文件末尾
			if (ch != ' '&&ch != EOF)
			{
				fseek(fp, -1L, SEEK_CUR);//将指针回退一字节，防止乱码
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
			while ((ch = getc(fp)) == ' ');//吃掉空格，便于判断文件末尾
			if (ch != ' '&&ch != EOF)
			{
				fseek(fp, -1L, SEEK_CUR);//将指针回退一字节，防止乱码
			}
		}
		chainfree(head);
		head = NULL;
		fclose(fp);
		fclose(nf);
		remove(fname1);
		printf("请输入另一要录入的项目(空行结束录入)：\n");
		n = get2(witem);
		if (n == 0)
			break;
		for (k = 0;; k++)
		{
			if (k > 0)
			{
				printf("请输入所要录入的项目(带性别，如男子篮球、女子足球）：\n");
				scanf("%s", witem);
			}
			ensex(witem, wsex);
			if (strcmp(wsex, "男") != 0 || strcmp(wsex, "女") != 0)
				break;
			else
				printf("请检查项目是否带上性别后重新输入：\n");
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