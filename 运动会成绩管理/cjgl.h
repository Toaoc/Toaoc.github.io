#pragma once
#ifndef _CJGL_H
#define _CJGL_H

typedef struct stu {
	char name[40];//姓名
	char sex[5];//性别
	char coll[40];//学院
	char item[30];//项目
	float score;//成绩
	int mark;//标记码,第一位代表取多少名，第二位：1、3代表从高排到低，2、4代表从低排到高，第三位代表得分
	struct stu *next;
}stu;

void wrifile(stu *head, char *fname, char xiuitem[][30]);//修改、删除模块的写入文件函数
void chaincheck(struct stu*head);
void search(void);//查询函数
void enter(void);//写入函数
void alter(void);//修改函数
void dele(void);//删除函数
struct stu *minsort(struct stu *head);//链表从小排到大的函数
void goal(char *gnname, struct stu * head);//用户自定义赋分函数
void chainfree(struct stu * head);//链表释放函数
struct stu *maxsort(struct stu * head);//链表从大排到小的函数
void color(short int x);//颜色函数
char *s_gets(char *st, int n);//输入字符串检查函数
void correctfile(char *fname);//去除中间文件的函数

#endif // !_CJGL_H

