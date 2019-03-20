#pragma once
#ifndef _CJGL_H
#define _CJGL_H

typedef struct stu {
	char name[40];
	char sex[5];
	char coll[40];
	char item[30];
	float score;
	int mark;//标记码,第一位代表取多少名，第二位：1代表从高排到低，2代表从低排到高，第三位代表得分
	struct stu *next;
}stu;

void wrifile(stu *head, char *fname, char xiuitem[][30]);
void chaincheck(struct stu*head);
void search(void);
void enter(void);
void alter(void);
void dele(void);
struct stu *minsort(struct stu *head);
void goal3(struct stu * head);
void goal5(struct stu * head);
void chainfree(struct stu * head);
struct stu *maxsort(struct stu * head);
void color(short int x);
char *s_gets(char *st, int n);
void correctfile(char *fname);

#endif // !_CJGL_H

