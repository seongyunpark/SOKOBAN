#pragma once

#define EMPTY 0			//��ĭ
#define WALL 1			//��, ���ع�(����, �浹)

#define CHARACTER 2		//������ ĳ����(Ŀ��?????)
#define BOX 3			//������ ��, ���ع�(������ ������)
#define DESTINATION 4	//������

//Ű �Է� ����
#define KEY_LEFTMOVE 101
#define KEY_RIGHTMOVE 102
#define KEY_DOWNMOVE 103
#define KEY_UPMOVE 104
#define KEY_NONE 106

//void InitGameBoard();
//void SetCharacter(int x, int y, int characternum);		//ĳ���� �ʱ�ȭ

void DrawUI();

//���ӳ����� �Լ�
bool isEnd();

//ȭ�� ������
void ClearScreen();

//Ű�Է��Լ�
int KeyInput();

//�� �׸��� �Լ�
void DrawAll();

void DrawOneBlock(int posX, int posY, int type);
//void DrawAll2();

//������ �޼� �Լ�(������ == �ڽ�)
void MakeDestination();
 
void reDrawMap();
void reInitMap();
// ĳ������ �̵� �� üũ (�浹���� - �� ����, ���� �б�, ��)
int CheckCharacterMove(int nowPosX, int nowPosY, int offsetX, int offsetY);
// ĳ���͸� �׸���.
void DrawCharacter(int posX, int posY);
//�ڽ��� �̵� �� üũ
//int CheckBoxMove(int nowPosX, int nowPosY, int offsetX, int offsetY);