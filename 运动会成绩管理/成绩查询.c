#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<io.h>
#include "cjgl.h"
void killdot(char *str);
void sdisplay1(void);//查询的主目录
void sdisplay2(char tem[]);//按届查询的目录
void search2(void);//按届查询的函数
void seacol(char *colname);//在全部文件里查询学院的函数
void seaname(char *stuname);//在全部文件里查询学生的函数
typedef struct fen {
	char coll[40];
	int score;
	struct fen *next;
}fen;//计算学院总分的结构体
struct fen *totalsort(fen *head);//对总分进行排序的函数
void sdisplay1(void)//主界面
{
	system("cls");
	printf("***********************运动会成绩管理系统*********************\n");
	printf("\t\t\t1.按届查询\n");
	printf("\t\t\t2.按学院查询\n");
	printf("\t\t\t3.按学生查询\n");
	printf("\t\t\t4.返回上一层\n");
	printf("\t\t\t5.退出程序\n");
	printf("请输入数字1-5执行程序：\n");
}

void search(void)//主函数
{
	int select;
	select = 0;
	char ch;
	while (select != 4)
	{
		sdisplay1();
		while (scanf("%d", &select) != 1)
		{
			while ((ch = getchar() != '\n') && ch != EOF);
			printf("输入错误，请重新输入：\n");
		}
		switch (select)
		{
		case 1:search2();//按届查询
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
		case 4:
			break;
		case 5:
			exit(0);
		default:
			printf("请输入数字1-5：\n");
		}
	}
}
void sdisplay2(char tem[])
{
	system("cls");
	printf("\t\t\t1、%s届学院总分报表查询\n",tem);
	printf("\t\t\t2、%s届学院成绩查询\n",tem);
	printf("\t\t\t3、%s届个人成绩查询\n",tem);
	printf("\t\t\t4、%s届项目成绩查询\n",tem);
	printf("\t\t\t5、%s届全部成绩\n",tem);
	printf("\t\t\t6、返回上一层\n");
	printf("\t\t\t7、退出程序\n");
	printf("请输入数字1-7执行程序：\n");
}
void search2(void)
{
	FILE *fp;
	int a, rank;//rank用于输出排名
	char ch;
	char sname[40], tem[15], fname[30], scoll[40], sitem[30], rankitem[30] ,rankcoll[30];//带s的用于临时储存，rankitem用于记录要排名的项目
	system("cls");
	printf("请输入要查询的届数：\n");
	scanf("%s",tem);
	strcpy(fname, tem);
	correctfile(fname);
	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		printf("文件不存在或无法打开\n");
		exit(EXIT_FAILURE);
	}
	//sdisplay2(tem);
	sdisplay2(tem);
	int choice;
	while (scanf("%d", &choice) != 1)
	{
		while ((ch = getchar() != '\n') && ch != EOF);
		printf("输入错误，请重新输入：\n");
	}
	stu *current, *prev, *head;
	current = NULL;
	head = NULL;
	prev = NULL;
	while (!feof(fp))//建立整个文件的链表
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
	fclose(fp);
	//head=sort(head);
	while(choice!=6)
	{
		if (choice == 0)
		{
			sdisplay2(tem);
			while (scanf("%d", &choice) != 1)
			{
				while ((ch = getchar() != '\n') && ch != EOF);
				printf("输入错误，请重新输入：\n");
			}
		}
		switch (choice)
		{
		case 1:
		{

			fen *first, *p, *bef, *point;//bef指前一个指针
			int nc = 0, ic;
			stu  *q, *qpre;

			first = p = bef = NULL;
			current = head;
			if (NULL == first)//建立第一个节点
			{
				first = (fen*)malloc(sizeof(fen));
				strcpy(first->coll, current->coll);
				first->score = 0;
				bef = p = first;
			}
			for (q = qpre = head; q != NULL; qpre = q, q = q->next)//建立链表，链表内容为不同学院
			{

				if (strcmp(current->coll, q->coll) != 0)
				{
					for (point = first, ic = 0; point != p->next; point = point->next)//找出不同学院
					{
						if (strcmp(q->coll, point->coll) == 0)
							ic++;
					}
					if (ic > 0)
						continue;
					p = (fen*)malloc(sizeof(fen));
					bef->next = p;
					p->score = 0;
					strcpy(p->coll, q->coll);
					bef = p;
				}
			}
			p->next = NULL;
			for (p = first; p != NULL; p = p->next)//建立该链表的另一内容，总分
			{

				for (qpre = q = head; q != NULL; qpre = q, q = q->next)
				{
					if (strcmp(p->coll, q->coll) == 0)
					{
						if (((q->mark % 100) / 10 == 3 || (q->mark % 100) / 10 == 4) && strcmp(qpre->coll, q->coll) == 0 && strcmp(qpre->item, q->item) == 0)
						{
							if (q != head)
								continue;
						}
						p->score = p->score + (q->mark % 10);
					}
				}
			}
			first = totalsort(first);//对总分链表进行排名
			printf("\n");
			printf("学院\t\t团体总分\t排名\t\n");
			for (a = 1,p = first; p != NULL;a++)
			{
				color(a);
				printf("%s\t%d\t%10d\n", first->coll, first->score,a);
				color(4);//恢复程序原有颜色
				first = p->next;
				free(p);
				p = first;
			}
			printf("\n");
			printf("继续%s届查询请按1\n查询其他届请按2\n退出程序请按3\n",tem);
			while (scanf("%d", &a) != 1)
			{
				while ((ch = getchar() != '\n') && ch != EOF);
				printf("输入错误，请重新输入：\n");
			}
			if (a == 1)
			{
				choice = 0;
				break;
			}
			if (a == 2)
				choice = 6;
			if (a == 3)
				exit(0);
		}
		break;
		case 2://按学院进行查询
		{
			int count[3] = { 0 };
			strcpy(rankcoll, "a");
			a = 1;//作为记录文件是否有所要查询的内容，并作为判断条件
			while (a == 1)
			{
				printf("请输入要查询的学院名称：\n\n");
				s_gets(scoll, 40);
				current = head;
				rank = 1;
				while (current != NULL)//从链表中寻找
				{
					if (strcmp(current->item, rankitem) != 0)
						rank = 1;//换了项目，重置排名
					else
					{
						if ((current->mark % 100) / 10 != 3 && (current->mark % 100) / 10 != 4)
							rank++;//用于记录排名
						else
						{
							if (strcmp(rankcoll, current->coll) != 0)
								rank++;
						}
					}
					if (strcmp(current->coll, scoll) == 0)
					{
						if (a == 1)
							printf("姓名\t性别\t学院\t项目\t成绩\t\t排名\n");
						if (rank < 4)
						{
							if ((current->mark % 100) / 10 == 3 || (current->mark % 100) / 10 == 4)
							{
								if (strcmp(current->coll, rankcoll) != 0)
									count[rank - 1]++;
							}
							else
								count[rank - 1]++;
						}
						color(rank);
						printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", current->name, current->sex, current->coll, current->item, current->score,rank);
						color(4);
						a++;
					}
					strcpy(rankcoll, current->coll);
					strcpy(rankitem, current->item);
					current = current->next;
				}
				if (a == 1)
					printf("没有此学院，请检查后重新输入\n");
				else
				{
					printf("共获得第一名%d项，第二名%d项，第三名%d项\n",count[0],count[1],count[2]);
				}
				strcpy(rankitem, "a");
				printf("\n继续进行学院查询请按1\n继续%s届查询请按2\n查询其他届请按3\n退出程序请按4\n", tem);
				while (scanf("%d", &a) != 1)
				{
					while ((ch = getchar() != '\n') && ch != EOF);
					printf("输入错误，请重新输入：\n");
				}
				switch (a)
				{
				case 1:
					break;
				case 2:choice = 0;
					break;
				case 3:choice = 6;
					break;
				case 4:exit(0);
				default:
					break;
				}
			}
		}
		break;
		case 3: //按姓名进行查询，原理与学院查询一样
		{
			a = 1;
			while (a == 1)
			{
				printf("请输入姓名：\n\n");
				s_gets(sname, 40);
				current = head;
				rank = 1;
				while (current != NULL)
				{
					if (strcmp(current->name, sname) == 0)
					{
						if (a == 1)
							printf("姓名\t性别\t学院\t项目\t成绩\t排名\n");
						if (strcmp(current->item, rankitem) != 0)
							rank = 1;
						else
						{
							if ((current->mark % 100) / 10 != 3 && (current->mark % 100) / 10 != 4)
								rank++;
						}
						printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", current->name, current->sex, current->coll, current->item, current->score,rank);
						a++;
						strcpy(rankitem, current->item);
					}
					current = current->next;
				}
				if (a == 1)
					printf("查无此人\n");
				strcpy(rankitem, "a");
				printf("\n继续进行姓名查询请按1\n继续%s届查询请按2\n查询其他届请按3\n退出程序请按4\n", tem);
				while (scanf("%d", &a) != 1)
				{
					while ((ch = getchar() != '\n') && ch != EOF);
					printf("输入错误，请重新输入：\n");
				}
				switch (a)
				{
				case 1:
					break;
				case 2:choice = 0;
					break;
				case 3:choice = 6;
					break;
				case 4:exit(0);
				default:
					break;
				}
			}
		}
		break;
		case 4://按项目进行查询，原理基本和学院查询一样
		{
			a = 1;
			while (a == 1)
			{
				printf("请输入项目名称(\033[1;31;47m带性别\033[0m，如\033[1;31;47m男子\033[0m跳高、\033[1;31;47m女子\033[0m跳远)：\n\n");
				s_gets(sitem, 30);
				current = head;
				while (current != NULL)
				{
					if (strcmp(current->item, sitem) == 0)
					{
						if (a == 1)
							printf("姓名\t性别\t学院\t项目\t成绩\t排名\n");
						color(a);
						printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", current->name, current->sex, current->coll, current->item, current->score,a);
						color(4);
						a++;
					}
					current = current->next;
				}
				if (a == 1)
					printf("没有此项目，请检查后重新输入！\n");
				printf("\n继续进行项目查询请按1\n继续%s届查询请按2\n查询其他届请按3\n退出程序请按4\n", tem);
				while (scanf("%d", &a) != 1)
				{
					while ((ch = getchar() != '\n') && ch != EOF);
					printf("输入错误，请重新输入：\n");
				}
				switch (a)
				{
				case 1:
					break;
				case 2:choice = 0;
					break;
				case 3:choice = 6;
					break;
				case 4:exit(0);
				default:
					break;
				}
			}
		}
		break;
		case 5://输出该届全部成绩
		{
			strcpy(rankcoll, "a");
			printf("姓名\t性别\t学院\t\t项目\t\t成绩\t排名\n");
			strcpy(rankitem, "a");
			for (rank = 1,current = head; current != NULL; current = current->next)
			{
				if (strcmp(rankitem, current->item) != 0)
				{
					rank = 1;
				}
				else
				{
					if (((current->mark % 100) / 10 == 3 || (current->mark % 100) / 10 == 4) && strcmp(rankcoll, current->coll) != 0)
						rank++;
					else if ((current->mark % 100) / 10 != 3 && (current->mark % 100) / 10 != 4)
						rank++;
				}
				color(rank);
				printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", current->name, current->sex, current->coll, current->item, current->score, rank);
				color(4);
				strcpy(rankcoll, current->coll);
				strcpy(rankitem, current->item);
			}
			printf("\n继续%s届查询请按1\n查询其他届请按2\n退出程序请按3\n", tem);
			while (scanf("%d", &a) != 1)
			{
				while ((ch = getchar() != '\n') && ch != EOF);
				printf("输入错误，请重新输入：\n");
			}
			switch (a)
			{
			case 1:choice = 0;
				break;
			case 2:choice = 6;
				break;
			case 3:exit(0);
			default:
				break;
			}
		}
		break;
		case 7:exit(0);
		}
	}
	chainfree(head);
}
void seacol(char *colname)//输出历年学院成绩
{

	long Handle;
	FILE *fp;
	char scname[40], scsex[5], scitem[30], sccol[40], str[20], rankitem[30];
	float scsco;
	int  scmark, rank, n;
	struct _finddata_t FileInfo;

	if ((Handle = _findfirst("*.txt", &FileInfo)) == -1L)//寻找全部txt文件，并判断是否存在

		printf("暂无运动会成绩，请进行录入\n");

	else

	{

		//printf("%s\n", FileInfo.name);
		strcpy(str, FileInfo.name);//str用于输出年份
		killdot(str);//把年份名提取出来，即把'.'变为'\0'
		printf("%s:\n", str);
		printf("姓名\t性别\t学院\t\t项目\t\t成绩\t排名\n");
		fp = fopen(FileInfo.name, "r  ");
		rank = 1;
		while (!feof(fp))//输出第一个文件符合要求的结果
		{
			if (fscanf(fp, "%s%s%s%s%f%d", scname, scsex, sccol, scitem, &scsco, &scmark) != 6)
				break;
			if (strcmp(scitem, rankitem) != 0)
				rank = 1;
			else
			{
				if ((scmark % 100) / 10 != 3 && (scmark % 100) / 10 != 4)
					rank++;
			}
			if (strcmp(sccol, colname) == 0)
				printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", scname, scsex, sccol, scitem, scsco, rank);
			strcpy(rankitem, scitem);
		}
		fclose(fp);
		//printf('\n');
		n = 0;
		while (_findnext(Handle, &FileInfo) == 0)//输出其他文件符合要求的结果
		{
			//printf("%s\n", FileInfo.name);
			strcpy(str, FileInfo.name);
			killdot(str);
			rank = 1;
			if (strlen(str) < 7)
			{

				printf("%s:\n", str);
				printf("姓名\t性别\t学院\t\t项目\t\t成绩\t排名\n");
				fp = fopen(FileInfo.name, "r");
				while (!feof(fp))
				{
					n = 0;
					if (fscanf(fp, "%s%s%s%s%f%d", scname, scsex, sccol, scitem, &scsco, &scmark) != 6)
						break;
					if (strcmp(scitem, rankitem) != 0)
						rank = 1;
					else
					{
						if ((scmark % 100) / 10 != 3 && (scmark % 100) / 10 != 4)
							rank++;
					}
					if (strcmp(sccol, colname) == 0)
					{
						printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", scname, scsex, sccol, scitem, scsco, rank);
						n++;
					}
					strcpy(rankitem, scitem);
				}
				fclose(fp);
			}
			if (n != 0)
				while (getchar() != '\n');
			//printf('\n');
		}
		getchar();
		printf("Enter键结束该项查询");
		while (getchar() != '\n');
		_findclose(Handle);

	}
}
void seaname(char *stuname)//输出某学生历年成绩，原理同上
{

	long Handle;
	FILE *fp;
	char scname[40], scsex[5], scitem[30], sccol[40], str[20], rankitem[30];
	float scsco;
	int  scmark, rank, n;
	struct _finddata_t FileInfo;

	if ((Handle = _findfirst("*.txt", &FileInfo)) == -1L)

		printf("暂无运动会成绩，请进行录入\n");

	else

	{

		//printf("%s\n", FileInfo.name);
		strcpy(str, FileInfo.name);
		killdot(str);
		printf("%s:\n", str);
		printf("姓名\t性别\t学院\t\t项目\t\t成绩\t排名\n");
		//printf("%s:\n", str);
		
		fp = fopen(FileInfo.name, "r ");
		rank = 1;
		while (!feof(fp))
		{
			if (fscanf(fp, "%s%s%s%s%f%d", scname, scsex, sccol, scitem, &scsco, &scmark) != 6)
				break;
			if (strcmp(scitem, rankitem) != 0)
				rank = 1;
			else
			{
				if ((scmark % 100) / 10 != 3 && (scmark % 100) / 10 != 4)
					rank++;
			}
			if (strcmp(scname, stuname) == 0)
			{
				printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", scname, scsex, sccol, scitem, scsco,rank);
			}
			strcpy(rankitem, scitem);
		}
		fclose(fp);
		//printf('\n');
		n = 0;
		while (_findnext(Handle, &FileInfo) == 0)
		{
			//printf("%s\n", FileInfo.name);
			strcpy(str, FileInfo.name);
			killdot(str);
			//printf("%s:\n", str);
			/*printf("%s:\n", str);
			printf("姓名\t性别\t学院\t\t项目\t\t成绩\t排名\n");*/
			if (strlen(str) < 7)
			{
				printf("%s:\n", str);
				printf("姓名\t性别\t学院\t\t项目\t\t成绩\t排名\n");
				fp = fopen(FileInfo.name, "r+");
				rank = 1;
				while (!feof(fp))
				{
					n = 0;
					if (fscanf(fp, "%s%s%s%s%f%d", scname, scsex, sccol, scitem, &scsco, &scmark) != 6)
						break;
					if (strcmp(scitem, rankitem) != 0)
						rank = 1;
					else
					{
						if ((scmark % 100) / 10 != 3 && (scmark % 100) / 10 != 4)
							rank++;
					}
					if (strcmp(scname, stuname) == 0)
					{
						printf("%s\t%s\t%s\t%-12s\t%.2f\t%d\n", scname, scsex, sccol, scitem, scsco, rank);
						n++;
					}
					strcpy(rankitem, scitem);
				}
				fclose(fp);
			}
			if(n != 0)
				while (getchar() != '\n');
			//printf('\n');
		}
		getchar();
		printf("Enter键结束该项查询");
		while (getchar() != '\n');
		_findclose(Handle);

	}
}
void killdot(char *str)//将文件名的'.'换成'\0'
{
	int i;
	for (i = 0; str[i] != '.'; i++);
	str[i] = '\0';
	//return  str;
}
struct fen *totalsort(fen *head)//团体总分排名
{
	fen *pfirst = NULL;
	fen *ptail = NULL;
	fen *pmaxBefore = NULL;
	fen *pmax = NULL;
	fen *p = NULL;
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