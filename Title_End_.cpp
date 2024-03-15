#include <stdio.h>
#include "sokoban.h"
#include "Title_End_.h"
#include "ConsoleLib.h"
#include <windows.h>

// 소코반 게임 타이틀 화면
void MainTitleDraw()
{

	printf("=========================================\n");
	printf("         쏘코반쏘코반 게임입니당           \n");
	printf("                                         \n");
	printf("                  ☆                     \n");
	printf("                  ☆                     \n");
	printf("                  ☆                     \n");
	printf("                               by 성윤   \n");
	printf("=========================================\n");
	printf("       (1) 시작하기      (2) 나가기		 \n");
	printf("=========================================\n");
}

//타이틀 화면 메뉴 선택
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
		printf(" 게임을 시작합니다.\n");
		printf("      STAGE 1     \n");
		sleep(500);
		isValue = false;
		break;

	case 2:	
		PlaySound("menuSelectSound_beep.wav", NULL, SND_ASYNC);
		printf("게임을 나갑니다.\n");
		isValue = true;
		break;
	}

	return isValue;
}

// 게임엔딩화면
void GameEndTitle()
{
	printf("=========================================\n");
	printf("         쏘코반쏘코반 게임 끝~~~~          \n");
	printf("                                         \n");
	printf("                  ☆                     \n");
	printf("                  ☆                     \n");
	printf("                  ☆                     \n");
	printf("                               by 성윤   \n");
	printf("=========================================\n");
	printf("  (1) 다시하기  (2) 다음단계  (3) 나가기	 \n");
	printf("=========================================\n");
}

// 게임엔딩메뉴 선택
bool EndMain()
{
	bool isValue = false;
	int MenuNum = 0;

	scanf_s("%d", &MenuNum);

	switch (MenuNum)
	{
	case 1:
		PlaySound("menuSelectSound_beep.wav", NULL, SND_ASYNC);
		printf(" 게임을 다시 시작합니다.\n");
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
		printf("게임을 나갑니다.\n");
		isValue = true;
		break;
	}

	return isValue;
}