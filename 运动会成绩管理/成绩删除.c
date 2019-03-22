#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include "cjgl.h"
void dele(void)
{
	system("cls");
	stu *p, *q, *head, *current, *prev;
	p = NULL;
	q = NULL;
	head = NULL;
	current = NULL;
	prev = NULL;
	//p=head;
	//p=q=(struct Student*)malloc(LEN);
	FILE *fin;
	int i, j, k;
	j = 0;
	k = 0;
	char ch[30], ch1[30], aname[30], asex[5], acoll[30], aitem[30], fname[20];
	int amark, arr[30] = { 0 }, choice = 1, select = 0;
	char xiuitem[30][30] = { "a" };
	float ascore;
	//char a[1000];
	printf("请输入要修改的年份：\n");
	scanf("%s", fname);
	correctfile(fname);//去除中间文件
	fin = fopen(fname, "r");
	if (fin == NULL)
	{
		printf("打开文件失败！\n");
		exit(0);
	}
	printf("请输入要删除的学生姓名:\n");
	scanf("%s", ch);
	printf("请输入%s参加的项目(\033[1;31;47m带性别\033[0m)(如 \033[1;31;47m男子\033[0m跳远):\n",ch);
	scanf("%s", ch1);
	//fgets(a,1000,fin);
	for (i = 0; feof(fin) == 0; i++)//将文件的内容读到链表中进行查找
	{
		if (fscanf(fin, "%s%s%s%s%f%d", aname, asex, acoll, aitem, &ascore, &amark) != 6)
		{
			if (i == 0)
			{
				printf("该届成绩未录入，或该届信息已被破坏\n");
				exit(1);
			}
			break;
		}
		current = (stu*)malloc(sizeof(stu));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		strcpy(current->name, aname);//从这开始的六行是将从文件读到的内容复制到链表中
		strcpy(current->sex, asex);
		strcpy(current->coll, acoll);
		strcpy(current->item, aitem);
		current->score = ascore;
		current->mark = amark;
		prev = current;

	}
	current->next = NULL;
	while (choice != 2)
	{
		p = q = head;
		//for(i=0;i<1000;i++)
		//{
		while (strcmp(p->name, ch) != 0 || strcmp(p->item, ch1) != 0)
		{
			q = p;
			p = p->next;
			if (p->next == NULL)
			{
				break;
			}
			//printf("%s %s\n", p->name, p->coll);
		}
		if (strcmp(p->name, ch) == 0 && strcmp(p->item, ch1) == 0)
		{
			printf("\n%s\t%s\t%s\t%s\t%.2f\n", p->name, p->sex, p->coll, p->item, p->score);
			printf("\n确认删除？\n1.删除\n2.不删除\n");
			while (scanf("%d", &choice) != 1||(choice != 1&&choice != 2))
				printf("输入错误，请重新输入");
			if (choice == 1)
			{
				arr[k] = p->mark % 10;
				if (arr[k] != 0)
				{
					strcpy(xiuitem[j], p->item);
					strcpy(xiuitem[j + 1], "a");
					j++;
				}
				k++;
				if (p == head)
					head = head->next;
				else
					q->next = p->next;
			}
		}
		else
			printf("%s的信息尚未录入！\n", ch);
		printf("继续删除请按1\n返回上一层请按2\n退出程序请按3\n");
		while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2 && choice != 3))
			printf("输入错误，请重新输入！\n");
		if (choice == 3)
		{
			choice = 2;
			select = 3;//用于保存后退出
		}
	}
	for (i = j = 0; i < 29; i++)
	{
		j = arr[i] + j;//检查删除的是否是前3名或前5名
	}
	if (j != 0)//删除的是前3或前5，排序后写入文件
	{
		fclose(fin);
		wrifile(head, fname, xiuitem);
		printf("删除成功！\n");
	}
	else//非前3、5，直接写入
	{
		for (p = head; p != NULL; p = p->next)
			fprintf(fin, " %s %s %s %s %.2f %d ", p->name, p->sex, p->coll, p->item, p->score, p->mark);
		fclose(fin);
		chainfree(head);
	}
	if (select == 3)
		exit(0);
}