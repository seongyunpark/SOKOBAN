#include "sokoban.h"
#include <windows.h>
#include "ConsoleLib.h"

//�� ��ü 
#define MAP_HEIGHT_ 11
#define MAP_WIDTH_ 19	

//ĳ���� (ũ��..?)
#define CHARACTER_HEIGHT 1
#define CHARACTER_WIDTH_ 1

//ĳ���� ��ġ �ʱ�ȭ
int CharacterX = 11;
int CharacterY = 8;

extern int g_CharNumMove;

///������ ����� . ����������
///���� 19, ���� 11
int GameBoard[MAP_HEIGHT_][MAP_WIDTH_] =
{
	0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
	0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
	0 ,0 ,0 ,0 ,1 ,3 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
	0 ,0 ,1 ,1 ,1 ,0 ,0 ,3 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
	0 ,0 ,1 ,0 ,0 ,3 ,0 ,3 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
	1 ,1 ,1 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1,
	1 ,0 ,0 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,4 ,4 ,1,
	1 ,0 ,3 ,0 ,0 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4 ,4 ,1,
	1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,0 ,1 ,0 ,1 ,1 ,0 ,0 ,4 ,4 ,1,
	0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1,
	0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
};

//������ �ʱ�ȭ
int tempDestination[MAP_HEIGHT_][MAP_WIDTH_] = { 0, };

int tempGameBoard[MAP_HEIGHT_][MAP_WIDTH_] = { 0, };

// �� �ٽ� �׷�����....
void reDrawMap()
{
	for (int y = 0; y < 11; y++)
	{
		for (int x = 0; x < 19; x++)
		{
			tempGameBoard[y][x] = GameBoard[y][x];
		}
	}
}

void reInitMap()
{
	for (int y = 0; y < 11; y++)
	{
		for (int x = 0; x < 19; x++)
		{
			GameBoard[y][x] = tempGameBoard[y][x];
		}
	}


}


//�����ǿ��� �������� �ڽ��� �� ���� �� Ȯ��!
void MakeDestination()
{
	for (int y = 0; y < MAP_HEIGHT_; y++)
	{
		for (int x = 0; x < MAP_WIDTH_; x++)
		{
			if (GameBoard[y][x] == 4)
			{
				tempDestination[y][x] = 4;
			}
		}
	}
}

///���� ĳ����
//int GameCharacter[8][11] = { 2 };

//�������� �ʱ�ȭ�Ѵ�.
/*
void InitGameBoard()
{
	//�迭�� ����ΰ�, ���� ����� �ش�.
	for (int y = 0; y < MAP_HEIGHT_; y++)
	{
		for (int x = 0; x < MAP_WIDTH_; x++)
		{
			if (GameBoard[y][x] == 1)
			{
				GameBoard[y][x] = WALL;
			}
			else if (GameBoard[y][x] == 0)
			{
				GameBoard[y][x] = EMPTY;
			}
			else if (GameBoard[y][x] == 2)
			{
				GameBoard[y][x] = CHARACTER;
			}
			else if (GameBoard[y][x] == 3)
			{
				GameBoard[y][x] = BOX;
			}
		}
	}
}
*/

/// �Է�
// Ű �Է�, �׿� ���� �̵� ���� ������ش�.
int KeyInput()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		return KEY_LEFTMOVE;
	}

	else if (GetAsyncKeyState(VK_RIGHT))
	{
		return KEY_RIGHTMOVE;
	}

	else if (GetAsyncKeyState(VK_UP))
	{
		return KEY_UPMOVE;
	}

	else if (GetAsyncKeyState(VK_DOWN))
	{
		return KEY_DOWNMOVE;
	}

	return KEY_NONE;
}

/// �׸���
// �������� ��� �׸���.
void DrawAll()
{
	for (int y = 0; y < 11; y++)
	{
		for (int x = 0; x < 19; x++)
		{
			// �������� �������� �������� ����, �������� ��ĭ�̸�
			if (tempDestination[y][x] == DESTINATION && GameBoard[y][x] == EMPTY)
			{
				// �����ǿ� �������� ����
				GameBoard[y][x] = DESTINATION;
			}


			DrawOneBlock(x, y, GameBoard[y][x]);


			// Ư�� ��ġ�� ���� �ϳ� �׸���.
		}
	}
}

// ���� �� UI ��Ÿ���� �Լ�
void DrawUI()
{
	// �� ��ü�� ���鼭 �ڽ��� �������� ���� �ߴ��� Ȯ��.
	int CompleteBox = 0;

	for (int y = 0; y < 11; y++)
	{
		for (int x = 0; x < 19; x++)
		{
			if (tempDestination[y][x] == DESTINATION && GameBoard[y][x] == BOX)
			{
				// �������� �ڽ� ��� �� �� ���� �ڽ� ++
				CompleteBox++;
			}
		}
	}

	// �ڽ� ���� ���� �Լ�
	LHLocateCursor(0, 13);
	printf("������ �ڽ��� ������? : %d\n", CompleteBox);

	// ĳ������ ������ ���� �Լ�
	LHLocateCursor(0, 12);
	printf(" ĳ������ ������ Ƚ����? : %d\n", g_CharNumMove);

	// UI ���� ���
	LHLocateCursor(0, 15);
	printf(" �̵� Ű : �� �� �� �� \n");
}

// ������ ������(�������� �ڽ��� �� ����) ���� �Ϸ�! 
bool isEnd()
{
	int check = 0;
	for (int y = 0; y < 11; y++)
	{
		for (int x = 0; x < 19; x++)
		{
			//�������� �ڽ��� �� ����? �Ϸ�
			if (tempDestination[y][x] == DESTINATION && GameBoard[y][x] == BOX)
			{
				check++;
			}
			// Ư�� ��ġ�� ���� �ϳ� �׸���.
		}
	}
	// ���� 6���� üũ�ϸ鼭 �ڽ� 6���� �������� �� �ö�Դ���!
	if (check == 6)
	{
		return true;
	}
	//�ƴϸ� �۵� ����
	return false;
}

void ClearScreen()
{
}

// �� ���� ���� ���
void DrawOneBlock(int posX, int posY, int type)
{
	switch (type)
	{
	case EMPTY:
	{
		LHPutAttrCharEx(posX * 2, posY, "  ", BG_WHITE, FG_WHITE);
	}
	break;

	case WALL:
	{
		LHPutAttrCharEx(posX * 2, posY, "��", BG_BLUE, FG_WHITE);
	}
	break;

	case BOX:
	{
		LHPutAttrCharEx(posX * 2, posY, "��", BG_PURPLE, FG_WHITE);
	}
	break;

	case DESTINATION:
	{
		LHPutAttrCharEx(posX * 2, posY, "��", BG_GREEN, FG_WHITE);
	}
	break;
	}
}

// ĳ������ �̵� �� üũ (�浹���� - �� ����, ���� �б� ��)
int CheckCharacterMove(int nowPosX, int nowPosY, int offsetX, int offsetY)
{
	// ���� ĳ���Ͱ� �ִ� ��ġ�� ��ȿ�Ѱ�?

	// �̵��ؾ� �� ��ġ�� ��ȿ�Ѱ�?
	int _nextPosX = nowPosX + offsetX;
	int _nextPosY = nowPosY + offsetY;


	/// 1. �̵��� ��ġ�� �������� ���̸�, �ƹ� �͵� ���� �ʴ´�.
	// ������ ���� üũ - ������ ������ �ǳ�?
	if (_nextPosX < 0 || 18 < _nextPosX || _nextPosY < 0 || 10 < _nextPosY)
	{
		return false;
	}

	/// 2-p. �̵��� ��ġ�� ���ڰ� �ִٸ�, ���ڸ� �δ�.
	if (GameBoard[_nextPosY][_nextPosX] == BOX)
	{
		// �ڽ��� �̵��� �� ����Ǵ� �͵�
		if (CheckCharacterMove(_nextPosX, _nextPosY, offsetX, offsetY) == true)
		{

			// �̵��ؾ� �� �ڽ� ��ġ�� �̵����� �ش�.
			GameBoard[_nextPosY + offsetY][_nextPosX + offsetX] = BOX;

			// ���� �ڽ� ��ġ�� ��ĭ�� �Ǿ�� �Ѵ�.
			GameBoard[_nextPosY][_nextPosX] = EMPTY;

			return true;
		}

		// �� �ܿ��� �� ��������.
		return false;
	}

	/// 3. �̵��� ��ġ�� �� ĭ�̸�, �̵��Ѵ�.
	if (GameBoard[_nextPosY][_nextPosX] == EMPTY)
	{
		return true;
	}

	/// 4. ���� �ε����� �������� �ʴ´�.(�����߻�)
	//if (GameBoard[_nextPosY][_nextPosX] == WALL)
	//{
	//	GameBoard[_nextPosY + offsetY][_nextPosX + offsetX] = WALL;
	//
	//	return false;
	//}

	/// 5. �̵��� �ڽ��� ��ġ�� ���������, �̵� �����ϴ�.
	if (GameBoard[_nextPosY][_nextPosX] == DESTINATION)
	{
		return true;
	}

	/// �̵� ���� �ƴϸ� �̵����� ���Ѵ�.
	return false;
}

// ĳ���͸� �� ���� ���� �׷��ش�.
void DrawCharacter(int posX, int posY)
{
	LHPutAttrCharEx(posX * 2, posY, "��", BG_RED, FG_WHITE);
}