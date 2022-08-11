#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define ROW 22 //��Ϸ������
#define COL 42 //��Ϸ������

#define KONG 0 //��ǿգ�ʲôҲû�У�
#define WALL 1 //���ǽ
#define FOOD 2 //���ʳ��
#define HEAD 3 //�����ͷ
#define BODY 4 //�������

#define UP 72 //���������
#define DOWN 80 //���������
#define LEFT 75 //���������
#define RIGHT 77 //���������
#define SPACE 32 //��ͣ
#define ESC 27 //�˳�

//��ͷ
struct Snake
{
	int len; //��¼������
	int x; //��ͷ������
	int y; //��ͷ������
}snake;

//����
struct Body
{
	int x; //���������
	int y; //����������
}body[ROW * COL]; //�������Դ洢����Ľṹ������

int face[ROW][COL]; //�����Ϸ������λ�õ�״̬

//���ع��
void HideCursor();
//�����ת
void CursorJump(int x, int y);
//��ʼ������
void InitInterface();
//��ɫ����
void color(int c);
//���ļ���ȡ��߷�
void ReadGrade();
//������߷ֵ��ļ�
void WriteGrade();
//��ʼ����
void InitSnake();
//�������ʳ��
void RandFood();
//�жϵ÷������
void JudgeFunc(int x, int y);
//��ӡ���븲����
void DrawSnake(int flag);
//�ƶ���
void MoveSnake(int x, int y);
//ִ�а���
void run(int x, int y);
//��Ϸ�����߼�����
void Game();

int max, grade; //ȫ�ֱ���