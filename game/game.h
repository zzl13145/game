#define ROW 3
#define COL 3
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//����
void InitBorad(char borad[ROW][COL], int row, int col);
void DisplayBorad(char borad[ROW][COL], int row, int col);
void PlayMove(char borad[ROW][COL], int row,int col);
void ComputerMove(char borad[ROW][COL], int row, int col);




//��������������Ϸ״̬
//���Ӯ  ��*��
//����Ӯ   ��#��
//ƽ��      ��Q��
//����       ��C��

char IsWin(char borad[ROW][COL], int row, int col);