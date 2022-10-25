#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBorad(char borad[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			borad[i][j] = ' ';
		}
	}
}


void DisplayBorad(char borad[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//1.打印一行的数据
			printf(" %c ", borad[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2.打印分割行
		if (i < row - 1)
		{
			for (j = 0;j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayMove(char borad[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走：>\n");
	while (1)
	{
		printf("请输入要下的坐标：>");
		scanf_s("%d%d", &x,&y);
		//判断x，y坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (borad[x - 1][y - 1] == ' ')
			{
				borad[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
}
void ComputerMove(char borad[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走：>\n");

	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (borad[x][y] == ' ')
		{
			borad[x][y] = '#';
			break;
		}
	}
}
//返回1表示棋盘满了
//返回0表示棋盘没满
int IsFull(char borad[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i <= row;i++)
	{
		for (j = 0;j <= col;j++)
		{
			if (borad[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;

}
char IsWin(char borad[ROW][COL], int row, int col)
{
	int i = 0;
	//判断横三行
	for (i = 0;i < row;i++)
	{
		if (borad[i][0] == borad[i][1] && borad[i][1] == borad[i][2] && borad[i][1] != ' ')
		{
			return borad[i][1];
		}
	}
	//判断竖三列
	for (i = 0;i < col;i++)
	{
		if (borad[0][i] == borad[1][i] && borad[1][i] == borad[2][i] && borad[1][i] != ' ')
		{
			return borad[1][i];
		}
	}
	//两个对角线
	if (borad[0][0] == borad[1][1] && borad[1][1] == borad[2][2] && borad[1][1] != ' ')
	{
		return borad[1][1];
	}
	if (borad[0][2] == borad[1][1] && borad[1][1] == borad[2][0] && borad[1][1] != ' ')
	{
		return borad[1][1];
	}
	//判断平局
	if (1 == IsFull(borad, row, col))
	{
		return 'Q';
	}
	return 'C';
}