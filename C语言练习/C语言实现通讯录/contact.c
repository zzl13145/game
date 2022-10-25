#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//��ʼ������
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}
//��
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷�����\n");
	}
	else
	{
		printf("���������֣�>");
		scanf("%s", ps->data[ps->size].name);
		printf("���������䣺>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�>");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰��>");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ��>");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("��ӳɹ�\n");
	}
}
static int FindByname(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0;i < ps->size;i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;//�ҵ���������
		}
	}
	return -1;//�Ҳ�������-1
}
//ɾ
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ������ϵ������:>");
	scanf("%s", name);
	//����Ҫɾ������ϵ�˵�λ��
	int pos = FindByname(ps, name);

	//ɾ��
	if (pos == -1)
		printf("Ҫɾ������ϵ�˲�����\n");
	else
	{
	  //ɾ������
		int j = 0;
		for (j = pos;j < ps->size - 1;j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}
//��
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ���ϵ������:>");
	scanf("%s", name);
	int pos = FindByname(ps, name);
	if (pos == -1)
		printf("�Ҳ�������ϵ��\n");
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}

}

//��
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ���ϵ������:>");
	scanf("%s", name);
	int pos = FindByname(ps, name);
	if (pos == -1)
		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
	else
	{
		printf("���������֣�>");
		scanf("%s", ps->data[pos].name);
		printf("���������䣺>");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰��>");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��>");
		scanf("%s", ps->data[pos].addr);

		printf("�޸ĳɹ�\n");
	}
}

//�Ƚ�����
int cmp_name(const void* e1, const void* e2)
{
	//�������ַ����Ƚ�->ʹ��strcmp����
	return strcmp(((struct Contact*)e1)->data->name, ((struct Contact*)e2)->data->name);
}
//����
void SortContact(struct Contact* ps)
{
	int sz = ps->size;
	qsort(ps, sz, sizeof(ps->data[sz]), cmp_name);
}
//��ӡ��Ϣ
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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