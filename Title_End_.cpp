#include <stdio.h>
#include "sokoban.h"
#include "Title_End_.h"
#include "ConsoleLib.h"
#include <windows.h>

// ���ڹ� ���� Ÿ��Ʋ ȭ��
void MainTitleDraw()
{

	printf("=========================================\n");
	printf("         ���ڹݽ��ڹ� �����Դϴ�           \n");
	printf("                                         \n");
	printf("                  ��                     \n");
	printf("                  ��                     \n");
	printf("                  ��                     \n");
	printf("                               by ����   \n");
	printf("=========================================\n");
	printf("       (1) �����ϱ�      (2) ������		 \n");
	printf("=========================================\n");
}

//Ÿ��Ʋ ȭ�� �޴� ����
bool MainWork()
{
	bool isValue = false;
	int MenuNum = 0;

	scanf_s("%d", &MenuNum);
	getchar();

	switch (MenuNum)
	{
	case 1:	
		PlaySound("menuSelectSound_beep.wav", NULL, SND_ASYNC);
		printf(" ������ �����մϴ�.\n");
		printf("      STAGE 1     \n");
		sleep(500);
		isValue = false;
		break;

	case 2:	
		PlaySound("menuSelectSound_beep.wav", NULL, SND_ASYNC);
		printf("������ �����ϴ�.\n");
		isValue = true;
		break;
	}

	return isValue;
}

// ���ӿ���ȭ��
void GameEndTitle()
{
	printf("=========================================\n");
	printf("         ���ڹݽ��ڹ� ���� ��~~~~          \n");
	printf("                                         \n");
	printf("                  ��                     \n");
	printf("                  ��                     \n");
	printf("                  ��                     \n");
	printf("                               by ����   \n");
	printf("=========================================\n");
	printf("  (1) �ٽ��ϱ�  (2) �����ܰ�  (3) ������	 \n");
	printf("=========================================\n");
}

// ���ӿ����޴� ����
bool EndMain()
{
	bool isValue = false;
	int MenuNum = 0;

	scanf_s("%d", &MenuNum);

	switch (MenuNum)
	{
	case 1:
		PlaySound("menuSelectSound_beep.wav", NULL, SND_ASYNC);
		printf(" ������ �ٽ� �����մϴ�.\n");
		printf("      STAGE 1     \n");
		Sleep(300);
		system("cls");
		reInitMap();
		//reDrawMap();
		//InitGameBoard;
		break;

	case 2:
		PlaySound("menuSelectSound_beep.wav", NULL, SND_ASYNC);
		// 
		break;
	case 3:
		PlaySound("menuSelectSound_beep.wav", NULL, SND_ASYNC);
		printf("������ �����ϴ�.\n");
		isValue = true;
		break;
	}

	return isValue;
}