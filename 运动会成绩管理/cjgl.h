#pragma once
#ifndef _CJGL_H
#define _CJGL_H

typedef struct stu {
	char name[40];//����
	char sex[5];//�Ա�
	char coll[40];//ѧԺ
	char item[30];//��Ŀ
	float score;//�ɼ�
	int mark;//�����,��һλ����ȡ���������ڶ�λ��1��3����Ӹ��ŵ��ͣ�2��4����ӵ��ŵ��ߣ�����λ����÷�
	struct stu *next;
}stu;

void wrifile(stu *head, char *fname, char xiuitem[][30]);//�޸ġ�ɾ��ģ���д���ļ�����
void chaincheck(struct stu*head);
void search(void);//��ѯ����
void enter(void);//д�뺯��
void alter(void);//�޸ĺ���
void dele(void);//ɾ������
struct stu *minsort(struct stu *head);//�����С�ŵ���ĺ���
void goal(char *gnname, struct stu * head);//�û��Զ��帳�ֺ���
void chainfree(struct stu * head);//�����ͷź���
struct stu *maxsort(struct stu * head);//����Ӵ��ŵ�С�ĺ���
void color(short int x);//��ɫ����
char *s_gets(char *st, int n);//�����ַ�����麯��
void correctfile(char *fname);//ȥ���м��ļ��ĺ���

#endif // !_CJGL_H

