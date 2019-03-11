#pragma once
#ifndef _CJGL_H
#define _CJGL_H

typedef struct stu {
	char name[40];
	char sex[5];
	char coll[40];
	char item[30];
	float score;
	int mark;//±ê¼ÇÂë
	struct stu *next;
}stu;

void chaincheck(struct stu*head);
void search(void);
//void write(void);
void alter(void);
struct stu *minsort(struct stu *head);
void goal3(struct stu * head);
void goal5(struct stu * head);
void chainfree(struct stu * head);
struct stu *maxsort(struct stu * head);
char *s_gets(char *st, int n);

#endif // !_CJGL_H

