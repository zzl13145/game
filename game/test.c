#define _CRT_SECURE_NO_WARNINGS 1
//����������
#include "game.h"
void menu()
{
	printf("****************************\n");
	printf("**** 1.play   0. exit  *****\n");
	printf("****************************\n");
}

//��Ϸ�������㷨ʵ��
void game()
{
	int ret = 0;
	//����-����߳���������Ϣ
	char borad[ROW][COL] = { 0 }; //ȫ���ո�
	//��ʼ������
	InitBorad(borad, ROW, COL);
	//��ӡ����
	DisplayBorad(borad, ROW, COL);
	 //����

	while (1)
	{

		//��������
		ComputerMove(borad, ROW, COL);
		DisplayBorad(borad, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(borad, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//�������
		PlayMove(borad,ROW, COL);
		DisplayBorad(borad, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(borad, ROW, COL);

		if (ret != 'C')
		{
			break;
		}


	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}

}
void test()
{
	int input;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("��ѡ��>");
		scanf_s("%d", &input);


		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);

}


int main()
{
	test();

	return 0;
}