#pragma once

#define EMPTY 0			//빈칸
#define WALL 1			//벽, 방해물(고정, 충돌)

#define CHARACTER 2		//움직일 캐릭터(커서?????)
#define BOX 3			//굴리는 공, 방해물(유동적 움직임)
#define DESTINATION 4	//목적지

//키 입력 정의
#define KEY_LEFTMOVE 101
#define KEY_RIGHTMOVE 102
#define KEY_DOWNMOVE 103
#define KEY_UPMOVE 104
#define KEY_NONE 106

//void InitGameBoard();
//void SetCharacter(int x, int y, int characternum);		//캐릭터 초기화

void DrawUI();

//게임끝나는 함수
bool isEnd();

//화면 깨끗이
void ClearScreen();

//키입력함수
int KeyInput();

//맵 그리는 함수
void DrawAll();

void DrawOneBlock(int posX, int posY, int type);
//void DrawAll2();

//목적지 달성 함수(목적지 == 박스)
void MakeDestination();
 
void reDrawMap();
void reInitMap();
// 캐릭터의 이동 시 체크 (충돌감지 - 벽 여부, 상자 밀기, 등)
int CheckCharacterMove(int nowPosX, int nowPosY, int offsetX, int offsetY);
// 캐릭터를 그린다.
void DrawCharacter(int posX, int posY);
//박스의 이동 시 체크
//int CheckBoxMove(int nowPosX, int nowPosY, int offsetX, int offsetY);