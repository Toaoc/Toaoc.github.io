#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include "cjgl.h"
void ensex(char *witem,char *wsex);//用于从项目中录入性别
void singlewrite(char*fname);//个人项目录入
void teamwrite(char*fname);//团体项目录入
int get2(char *str);//用于判断录入（通过返回值）
void enter(void)
{
	char fname[30], ch;//文件名（即年份）
	int choice;//用于记录用户的选择
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
		while (scanf("%d", &choice) != 1)//判断输入的是否是整型数
		{
			while ((ch = getchar() != '\n') && ch != EOF);
			printf("输入错误，请重新输入：\n");
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
		default:printf("请输入数字1-4执行程序：");
		}
		if (choice == 1 || choice == 2)
			break;
	}
}
void ensex(char *witem,char *wsex)
{
	int i;
	for (i = 0; i != 2; i++)//从项目中截取两个字节作为性别
		wsex[i] = witem[i];
	wsex[i] = '\0';
	printf("%s\t%s\n", witem, wsex);
}
void singlewrite(char *fname)
{
	FILE *fp, *nf, *ff;
	stu * head, *prev, *current;
	char  wname[40], wsex[5], wcoll[30], witem[20], fname1[20], ch, gitem[30], gname[20];//带w的都是用来暂时存储数据，防止直接对链表进行操作时产生意外
	int a, b, wmark, i, j, k, n, defen[10], gmark, fbug, fbug2;//a,b用于生成标记码的前两位，a代表获奖名次，b代表排序方式
	float wscore;
	head = NULL;
	prev = NULL;
	current = NULL;
	fbug = 0;
	/*printf("请输入运动会届数：\n");
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
		printf("文件打开错误！\n");
		exit(EXIT_FAILURE);
	}*/
	for (k = 0;k!=-1; k++)//只有输入带性别的项目才能break
	{
		printf("请输入所要录入的项目(\033[1;31;47m带性别 \033[0m，如\033[1;31;47m男子\033[0m跳远、\033[1;31;47m女子\033[0m跳高）：\n");
		scanf("%s", witem);
		ensex(witem, wsex);//获取性别
		if (strcmp(wsex, "男") == 0 || strcmp(wsex, "女") == 0)
			break;
		else
			printf("请带上性别后重新输入：\n");
	}
	fbug2 = 0;
	//getchar();
	while (1)
	{
		rename(fname1, fname);
		rename(fname, fname1);//将原文件改为c.txt,使其成为中间文件
		fp = fopen(fname1, "a+");
		if (fp == NULL)
		{
			printf("文件打开错误！\n");
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
			printf("请输入该项目的获奖名次：\n");
			printf("1.取前3名\n2.取前5名\n3.自定义\n");
			while (scanf("%d", &a) != 1 )
			{
				while ((ch = getchar() != '\n') && ch != EOF);
				printf("输入错误，请重新输入要取的名次\n");
			}
			while (a < 1 || a > 3)
			{
				printf("输入错误，请重新输入要取的名次\n");
				while (scanf("%d", &a) != 1)
				{
					while ((ch = getchar() != '\n') && ch != EOF);
					printf("输入错误，请重新输入要取的名次\n");
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
				printf("请输入要取的名次(1-10)：\n");
				while (scanf("%d", &a) != 1 )
				{
					while ((ch = getchar() != '\n') && ch != EOF);
					printf("输入错误，请重新输入要取的名次\n");
				} 
				while (a < 1 || a > 10)
				{
					printf("输入错误，请重新输入要取的名次\n");
					while (scanf("%d", &a) != 1)
					{
						while ((ch = getchar() != '\n') && ch != EOF);
						printf("输入错误，请重新输入要取的名次\n");
					}

				}
				for (i = 1; i < a + 1; i++)
				{
					printf("请输入第%d名可获得的的分数：\n", i);
					while (scanf("%d", &defen[i - 1]) != 1)
					{
						while ((ch = getchar() != '\n') && ch != EOF);
						printf("输入错误，请重新输入第%d名可获得的的分数：\n", i);
					}
				}
				for (i = i - 1; i < 10; i++)
				{
					defen[i] = 0;
				}
				break;
			}
			default:printf("程序出bug，请截图后联系开发人员\n"); exit(1);
			}

			printf("该项目的好成绩为高数值还是低数值：\n1、高数值\n2、低数值\n");
			while ((i = scanf("%d", &b)) != 1 || (b != 1 && b != 2))
			{
				if (1 != i)
				{
					while ((ch = getchar() != '\n') && ch != EOF);
				}
				printf("输入错误，请重新输入\n");
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
		printf("\n请输入%s参赛者的姓名（空行结束该项目输入）：\n", witem);
		//getchar();//用于读取缓存区中遗留的换行符，防止判断出错
		if (fbug < 2)
			getchar();
		while (s_gets(wname, 45) != NULL && wname[0] != '\0')//判断用户的输入
		{
			current = (stu*)malloc(sizeof(stu));
			if (head == NULL)
				head = current;
			else
				prev->next = current;
			strcpy(current->name, wname);//将用户输入记录到链表当中
			strcpy(current->item, witem);
			strcpy(current->sex, wsex);
			printf("%s\n", current->sex);
			printf("请输入%s所属学院：\n", wname);
			scanf("%s", current->coll);
			printf("请输入%s的成绩：\n", wname);
			while (scanf("%f", &current->score) != 1)
			{
				while ((ch = getchar() != '\n') && ch != EOF);
				printf("输入错误，请重新输入\n");
			}
			current->mark = gmark;//生成标记码前两位
			printf("录入成功！\n");
			prev = current;
			printf("请输入%s另一参赛者的姓名（空行结束该项目录入）：\n", witem);
			getchar();
		}
		if (head == NULL)
			break;
		rewind(fp);//将指针回调到开头，
		while (!feof(fp))//从文件中读取同项目到该链表中
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
		if ((head->mark % 100) / 10 == 1)//对链表进行排名并赋分
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
		for (current = head; current != NULL; current = current->next)//将链表里的内容写入到新文件中
		{
			fprintf(nf, " %s %s %s %s %.2f %d ", current->name, current->sex, current->coll, current->item, current->score, current->mark);
		}
		rewind(fp);//将文件指针回调开始读取其他内容
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
				fprintf(nf, " %s %s %s %s %.2f %d ", wname, wsex, wcoll, witem, wscore, wmark);//将其他内容写入到新文件中
				fflush(fp);
			}
			while ((ch = getc(fp)) == ' ');//吃掉空格，便于判断文件末尾
			if (ch != ' '&&ch != EOF)
			{
				fseek(fp, -1L, SEEK_CUR);//将指针回退一字节，防止乱码
			}
		}
		chainfree(head);//释放链表
		head = NULL;
		fclose(fp);
		fclose(nf);
		remove(fname1);//将中间文件去除
		printf("请输入所要录入的项目(\033[1;31;47m带性别\033[0m，如\033[1;31;47m男子\033[0m跳远、\033[1;31;47m女子\033[0m跳高），空行结束输入：\n");
		n = get2(witem);
		if (n == 0)//n=0即表示用户直接按下了回车键
			break;
		for (k = 0;; k++)//判断并读取性别
		{
			if (k > 0)
			{
				printf("请输入所要录入的项目(\033[1;31;47m带性别\033[0m，如\033[1;31;47m男子\033[0m跳远、\033[1;31;47m女子\033[0m跳高）：\n");
				scanf("%s", witem);
			}
			ensex(witem, wsex);
			if (strcmp(wsex, "男") != 0 || strcmp(wsex, "女") != 0)
			{
				fbug2 = 1;
				break;
			}
			else
				printf("请带上性别后重新输入：\n");
		}

	}

}
void teamwrite(char*fname)//团体项目录入
{
	FILE *fp, *nf ,*ff;
	stu * head, *prev, *current;
	char  wname[40], wsex[5], wcoll[30], witem[20], fname1[20], ch, gname[20],gitem[30];//带w的都是用于临时储存的
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
	for (k = 0; k != -1; k++)//读取项目并判断性别
	{
		printf("请输入团体项目名称(\033[1;31;47m带性别\033[0m，如\033[1;31;47m男子\033[0m篮球、\033[1;31;47m女子\033[0m足球）：\n");
		scanf("%s", witem);
		ensex(witem, wsex);
		if (strcmp(wsex, "男") == 0 || strcmp(wsex, "女") == 0)
			break;
		else
			printf("请带上性别后重新输入：\n");
	}
	fbug2 = 0;
	while (1)
	{
		rename(fname1, fname);
		rename(fname, fname1);//将原文件改成中间文件
		fp = fopen(fname1, "r");
		if (fp == NULL)
		{
			printf("文件打开错误！\n");
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
			printf("请输入该项目的获奖名次：\n");
			printf("1.取前3名\n2.取前5名\n3.自定义\n");
			while ((i = scanf("%d", &a)) != 1 || a < 1 || a > 3)
			{
				if(i!=1)
					while ((ch = getchar() != '\n') && ch != EOF);
				printf("输入错误，请重新输入要取的名次\n");
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
				printf("请输入要取的名次(1-10)：\n");
				while ((i = scanf("%d", &a) != 1) || a < 1 || a > 10)
				{
					if(i!=1)
						while ((ch = getchar() != '\n') && ch != EOF);
					printf("输入错误，请重新输入要取的名次\n");
				}
				for (i = 1; i < a + 1; i++)
				{
					printf("请输入第%d名可获得的的分数：\n", i);
					scanf("%d", &defen[i - 1]);
				}
				for (i = i - 1; i < 10; i++)
				{
					defen[i] = 0;
				}
				break;
			}
			default:printf("程序出bug，请截图后早开发人员\n"); exit(1);
			}
			printf("%s的1-%d名是否按数值成绩统一排名：\n1、是\n2、否\n", witem, a);
			while ((i = scanf("%d", &c)) != 1 || (c != 1 && c != 2))
			{
				if(i!=1)
					while ((ch = getchar() != '\n') && ch != EOF);
				printf("输入错误，请重新输入\n");
			}
			if (1 == c)
				b = c + 1;
			else
				b = 5;//赋值为5用于躲过下面几句输出
			if (2 == b)
			{
				printf("%s的好成绩为高数值还是低数值：\n1、高数值\n2、低数值\n", witem);
				while ((i=scanf("%d", &c)) != 1 || (c != 1 && c != 2))
				{
					if(i!=1)
						while ((ch = getchar() != '\n') && ch != EOF);
					printf("输入错误，请重新输入\n");
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
		printf("请输入%s参赛学院的名称：\n", witem);
		if(fbug < 2)
			getchar();
		while (s_gets(wcoll, 45) != NULL && wcoll[0] != '\0')
		{
			if (3 == b || 4 == b)//3为从大到小排，4为从小到大排
			{
				printf("请输入%s的成绩：\n", wcoll);
				while (scanf("%f", &wscore) != 1)
				{
					while ((ch = getchar() != '\n') && ch != EOF);
					printf("输入错误，请重新输入\n");
				}
				//scanf("%f", &wscore);
			}
			else
			{
				printf("请输入%s获得的名次：\n", wcoll);
				while (scanf("%f", &wscore) != 1)
				{
					while ((ch = getchar() != '\n') && ch != EOF);
					printf("输入错误，请重新输入\n");
				}
				b = 4;//将b改回为4，4即为从小到大排
			}
			printf("请输入%s的选手：\n", wcoll);
			getchar();//用于读取缓存的换行符，便于判断
			while (s_gets(wname,45) != NULL && wname[0] != '\0')
			{
				current = (stu*)malloc(sizeof(stu));
				if (head == NULL)
					head = current;
				else
					prev->next = current;
				strcpy(current->coll, wcoll);//将临时读取的写入到链表中
				strcpy(current->item, witem);
				strcpy(current->sex, wsex);
				strcpy(current->name, wname);
				current->score = wscore;
				current->mark = 100 * a + 10 * b;
				prev = current;
				printf("请输入%s另一选手的姓名（空行结束输入）：\n", wcoll);
			}
			printf("\n请输入%s另一参赛学院的名称（空行结束该项目录入）：\n", witem);
		}
		if (head == NULL)
			break;
		rewind(fp);
		fscanf(fp, "%s%s%s%s%f%d", wname, wsex, wcoll, witem, &wscore, &wmark);//先尝试读取，便于判断文件末尾
		i = 0;
		while (!feof(fp))//从文件中读取同一个项目的到这个链表中用于排名
		{
			if (!feof(fp) && i != 0)//i!=0用于防止文件第一个被重复读取
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
			while ((ch = getc(fp)) == ' ');//吃掉空格，便于判断文件末尾
			if (ch != ' '&&ch != EOF)
			{
				fseek(fp, -1L, SEEK_CUR);//将指针回退一字节，防止乱码
			}
		}
		current->next = NULL;

		if ((head->mark % 100) / 10 == 1 || (head->mark % 100) / 10 == 3)//排序、赋分
		{
			head = maxsort(head);
			goal(gname, head);
		}
		else
		{
			head = minsort(head);
			goal(gname, head);

		}

		nf = fopen(fname, "w");//将文件写入到新文件中
		for (current = head; current != NULL; current = current->next)
		{
			fprintf(nf, " %s %s %s %s %.2f %d ", current->name, current->sex, current->coll, current->item, current->score, current->mark);

		}
		rewind(fp);//回调指针，读取非录入的项目
		while (!feof(fp))
		{
			if (fscanf(fp, "%s%s%s%s%f%d", wname, wsex, wcoll, witem, &wscore, &wmark) != 6)
				break;
			for (current = head, j = 0; (current != NULL) && (!feof(fp)); current = current->next)
			{
				if (strcmp(current->name, wname) == 0)
					j++;//j用于记录是否有重名的
			}
			if (j == 0)
			{
				fprintf(nf, " %s %s %s %s %.2f %d ", wname, wsex, wcoll, witem, wscore, wmark);
				fflush(fp);
			}
			while ((ch = getc(fp)) == ' ');//吃掉空格，便于判断文件末尾
			if (ch != ' '&&ch != EOF)
			{
				fseek(fp, -1L, SEEK_CUR);//将指针回退一字节，防止乱码
			}
		}
		chainfree(head);//释放链表
		head = NULL;
		fclose(fp);
		fclose(nf);
		remove(fname1);//将中间文件移除
		printf("请输入另一要录入的项目(\033[1;31;47m带性别\033[0m，如\033[1;31;47m男子\033[0m篮球、\033[1;31;47m女子\033[0m排球），空行结束录入：\n");
		n = get2(witem);
		if (n == 0)
			break;
		for (k = 0;; k++)
		{
			if (k > 0)
			{
				printf("请输入所要录入的团体项目(\033[1;31;47m带性别\033[0m，如\033[1;31;47m男子\033[0m篮球、\033[1;31;47m女子\033[0m足球）：\n");
				scanf("%s", witem);
			}
			ensex(witem, wsex);
			if (strcmp(wsex, "男") != 0 || strcmp(wsex, "女") != 0)
			{
				fbug2 = 1;
				break;
			}
			else
				printf("请带上性别后重新输入：\n");
		}

	}

}
int get2(char *str)//将输入的换行号换成'\0',并返回'\0'所在位置
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