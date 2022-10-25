#define ROW 3
#define COL 3
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//声明
void InitBorad(char borad[ROW][COL], int row, int col);
void DisplayBorad(char borad[ROW][COL], int row, int col);
void PlayMove(char borad[ROW][COL], int row,int col);
void ComputerMove(char borad[ROW][COL], int row, int col);




//告诉我们四种游戏状态
//玩家赢  ‘*’
//电脑赢   ‘#’
//平局      ‘Q’
//继续       ‘C’

char IsWin(char borad[ROW][COL], int row, int col);