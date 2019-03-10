#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
void chaincheck(struct stu*head);
void display(void);//主界面显示函数
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
	int mark;//标记码
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
		default:printf("输入错误！请输入数字1、2或3！");
		}
	}
	return 0;

}
void display(void)
{
	printf("***********************运动会成绩管理系统*********************\n");
	printf("\t\t\t1.成绩查询\n");
	printf("\t\t\t2.成绩录入\n");
	printf("\t\t\t3.修改成绩\n");
	printf("\t\t\t4.退出\n");
	printf("请输入数字1-4执行程序:\n");
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
	printf("请输入运动会届数：\n");
	scanf("%s", fname);
	strcpy(fname1, fname);
	strcat(fname1, "c.txt");
	strcat(fname, ".txt");
	rename(fname, fname1);
	/*fp = fopen(fname, "a+");
	if (fp == NULL)
	{
		printf("文件打开错误！\n");
		exit(EXIT_FAILURE);
	}*/
	printf("请输入所要录入的项目(空行结束录入)：\n");
	while (s_gets(witem, 45) != NULL && witem[0] != '\0')
	{
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
	printf("\t\t\t1、学院总分报表\n");
	printf("\t\t\t2、学院成绩查询\n");
	printf("\t\t\t3、个人成绩查询\n");
	printf("\t\t\t4、各项目成绩查询\n");
	printf("\t\t\t5、按届输出全部成绩\n");
	printf("\t\t\t6、输出全部成绩\n");
	printf("\t\t\t7、返回上一层\n");
	printf("\t\t\t8、退出程序\n");
	printf("注意：在本次程序运行中录入的成绩需重启后方可查询\n");
	printf("请输入数字1-7执行程序：\n");
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
	fp = fopen("成绩.txt", "r+");
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
	case 3: //按姓名进行查询
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
		printf("返回上一层请按1\n退出程序请按2\n");
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
	printf("\t\t\t1、修改成绩\n");
	printf("\t\t\t2、删除成绩\n");
	printf("\t\t\t3、返回上一层\n");
	printf("\t\t\t4、退出程序\n");
	printf("请输入数字1-4以执行程序：\n");
}
void alter(void)//修改成绩的函数
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
struct stu *maxsort(stu *head)//该函数是从1个逐渐拉到多个的排法
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
				pmax = p->next;//找出最大的链节
			}
		}

		if (pfirst == NULL)
		{
			pfirst = pmax;//将最大链节赋给pfirst指针
			ptail = pmax;
		}
		else
		{
			ptail->next = pmax;
			ptail = pmax;//逐渐拉开排序
		}
		//printf("\t%s\t%.2f\n", ptail->name, ptail->score);
		if (pmax == head)
		{
			head = head->next;//若最大的链节为head，则将head去掉
		}
		else
		{
			pmaxBefore->next = pmax->next;//去掉最大的链节后再进行排序，类似冒泡
		}
	}
	if (pfirst != NULL)
	{
		ptail->next = NULL;
	}
	head = pfirst;
	return head;
}
struct stu *minsort(stu *head)//该函数是从1个逐渐拉到多个的排法
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
				pmin = p->next;//找出最大的链节
			}
		}

		if (pfirst == NULL)
		{
			pfirst = pmin;//将最大链节赋给pfirst指针
			ptail = pmin;
		}
		else
		{
			ptail->next = pmin;
			ptail = pmin;//逐渐拉开排序
		}
		//printf("\t%s\t%.2f\n", ptail->name, ptail->score);
		if (pmin == head)
		{
			head = head->next;//若最大的链节为head，则将head去掉
		}
		else
		{
			pminBefore->next = pmin->next;//去掉最大的链节后再进行排序，类似冒泡
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