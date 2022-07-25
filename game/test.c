#define _CRT_SECURE_NO_WARNINGS 1
//测试三子棋
#include "game.h"
void menu()
{
	printf("****************************\n");
	printf("**** 1.play   0. exit  *****\n");
	printf("****************************\n");
}

//游戏的整个算法实现
void game()
{
	int ret = 0;
	//数组-存放走出的棋盘信息
	char borad[ROW][COL] = { 0 }; //全部空格
	//初始化棋盘
	InitBorad(borad, ROW, COL);
	//打印棋盘
	DisplayBorad(borad, ROW, COL);
	 //下棋

	while (1)
	{

		//电脑下棋
		ComputerMove(borad, ROW, COL);
		DisplayBorad(borad, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(borad, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//玩家下棋
		PlayMove(borad,ROW, COL);
		DisplayBorad(borad, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(borad, ROW, COL);

		if (ret != 'C')
		{
			break;
		}


	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}

}
void test()
{
	int input;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择：>");
		scanf_s("%d", &input);


		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);

}


int main()
{
	test();

	return 0;
}