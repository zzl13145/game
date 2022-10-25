#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//初始化函数
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}
//增
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满，无法增加\n");
	}
	else
	{
		printf("请输入名字：>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄：>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别：>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话：>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址：>");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("添加成功\n");
	}
}
static int FindByname(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0;i < ps->size;i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;//找到返回坐标
		}
	}
	return -1;//找不到返回-1
}
//删
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除的联系人名字:>");
	scanf("%s", name);
	//查找要删除的联系人的位置
	int pos = FindByname(ps, name);

	//删除
	if (pos == -1)
		printf("要删除的联系人不存在\n");
	else
	{
	  //删除数据
		int j = 0;
		for (j = pos;j < ps->size - 1;j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}
//查
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找的联系人姓名:>");
	scanf("%s", name);
	int pos = FindByname(ps, name);
	if (pos == -1)
		printf("找不到该联系人\n");
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}

}

//改
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改的联系人姓名:>");
	scanf("%s", name);
	int pos = FindByname(ps, name);
	if (pos == -1)
		printf("要修改的联系人不存在\n");
	else
	{
		printf("请输入名字：>");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄：>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别：>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话：>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址：>");
		scanf("%s", ps->data[pos].addr);

		printf("修改成功\n");
	}
}

//比较名字
int cmp_name(const void* e1, const void* e2)
{
	//本质是字符串比较->使用strcmp函数
	return strcmp(((struct Contact*)e1)->data->name, ((struct Contact*)e2)->data->name);
}
//排序
void SortContact(struct Contact* ps)
{
	int sz = ps->size;
	qsort(ps, sz, sizeof(ps->data[sz]), cmp_name);
}
//打印信息
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0;i < ps->size;i++)
		{
			printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}