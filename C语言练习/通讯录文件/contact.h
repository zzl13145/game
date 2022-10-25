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
	char tele[MAX_TELE];//电话号码
	char addr[MAX_ADDR];//住址
};

//通讯录类型
struct Contact
{
	int capacity;//当前通讯录的剩余容量
	int size;//记录当前已经有的元素个数
	struct PeoInfo* data;//存放联系人的信息
};

//声明函数
void InitContact(struct Contact* ps);//初始化
void AddContact(struct Contact* ps);//增
void DelContact(struct Contact* ps);//删
void SearchContact(const struct Contact* ps);//查
void ModifyContact(struct Contact* ps);//改
void ShowContact(const struct Contact* ps);//显示
void SortContact(struct Contact* ps);//排序
void DestroyContact(struct Contact* ps);
void SaveContact(struct Contact* ps);//保存文件
void LoadContact(struct Contact* ps);//加载文件信息