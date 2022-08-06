#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//��ʼ������
void InitContact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(MAX * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		printf(" InitContact::%s\n", strerror(errno));
		return;
	}
	ps->size = 0;
	ps->capacity = MAX;
	LoadContact(ps);//�����ļ���Ϣ
}

void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		//����
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else
			printf("����ʧ��\n");
	}
}

void LoadContact(struct Contact* ps)//�����ļ���Ϣ
{
	struct PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	//��ȡ�ļ��ŵ�ͨѶ¼
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfRead))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}

	fclose(pfRead);
	pfRead = NULL;
}

//��
void AddContact(struct Contact* ps)
{
	//��鵱ǰͨѶ¼��ʣ������
	CheckCapacity(ps);
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
	/*if (ps->size == MAX)
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
	}*/
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
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}
//����
void SortContact(struct Contact* ps)
{
	int sz = ps->size;
	qsort(ps->data, sz, sizeof(ps->data[sz]), cmp_name);
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

//�ͷŶ�̬���ٵ��ڴ�
void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

//�����ļ�
void SaveContact(struct Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0; 
	}
	//дͨѶ¼�е����ݵ��ļ���
	int i = 0;
	for (i = 0;i < ps->size;i++)
	{
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfWrite); 
	}

	fclose(pfWrite);
	pfWrite = NULL;
}