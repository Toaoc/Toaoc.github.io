/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include "cjgl.h"
void wdisplay(void);
void write(void)
{
	system("cls");
	printf("注意！录入时请不要中途退出！！\n");
	FILE *fp, *nf;
	stu * head, *prev, *current;
	char  wname[40], wsex[5], wcoll[30], witem[20], fname[20], fname1[20], ch, rname[40][30] = { 'a' };
	int a, b, wmark, i, j;
	float wscore;
	head = NULL;
	prev = NULL;
	current = NULL;
	printf("请输入运动会届数：\n");
	scanf("%s", fname);
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
	/*printf("请输入所要录入的项目(空行结束录入)：\n");
	while (s_gets(witem, 45) != NULL && witem[0] != '\0')
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
			printf("请输入%s的性别：\n", wname);
			scanf("%s", current->sex);
			printf("请输入%s所属学院：\n", wname);
			scanf("%s", current->coll);
			printf("请输入%s的成绩：\n", wname);
			scanf("%f", &current->score);
			current->mark = 100 * a + 10 * b;
			printf("录入成功！\n");
			prev = current;
			printf("\n请输入%s另一参赛者的姓名（空行结束该项目录入）：\n", witem);
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
		printf("请输入另一要录入的项目(空行结束录入)：\n");

	}

}*/