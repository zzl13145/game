#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#define MAX 3

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

enum Option
{
	EXIT,ADD,DEL,SEARCH,MODIFY,SHOW,SORT,SAVE
};
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];//�绰����
	char addr[MAX_ADDR];//סַ
};

//ͨѶ¼����
struct Contact
{
	int capacity;//��ǰͨѶ¼��ʣ������
	int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ���
	struct PeoInfo* data;//�����ϵ�˵���Ϣ
};

//��������
void InitContact(struct Contact* ps);//��ʼ��
void AddContact(struct Contact* ps);//��
void DelContact(struct Contact* ps);//ɾ
void SearchContact(const struct Contact* ps);//��
void ModifyContact(struct Contact* ps);//��
void ShowContact(const struct Contact* ps);//��ʾ
void SortContact(struct Contact* ps);//����
void DestroyContact(struct Contact* ps);
void SaveContact(struct Contact* ps);//�����ļ�
void LoadContact(struct Contact* ps);//�����ļ���Ϣ