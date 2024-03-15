//�ܼ� �׷��� ���̺귯��
#include "ConsoleLib.h"
//���ڹ� ����
#include "sokoban.h"
#include "Title_End_.h"
#include "windows.h"
#include <stdlib.h>
#include "playsoundapi.h"

int g_CharNumMove = 0;

///���� �Լ� ����
int main()
{
	PlaySound("SokobanGameBGM.wav", NULL, SND_ASYNC | SND_LOOP);
	
	reDrawMap();

	MainTitleDraw();

	if (MainWork() == true)
	{
		return 0;
	}

	system("cls");


	/// �ʱ�ȭ
	if (Initialize() == FALSE)
	{
		return 0;
	}

	///�ܼ� â�� Ÿ��Ʋ ����
	SetConsoleTitle("���ڹ�!");

	///Ŀ�� ������ ����...?
	LHSetCursor(20, FALSE);

	/// ��ũ�� ������ ����
	set_screen_size(60, 30);

	/// ���ڹ� ����

	//�ʱ�ȭ(���� ���� ��, �� �ѹ��� �Ͼ�� �ϴ� ��)
	//InitGameBoard();

	/// ���ڹ�(Ŭ����)���� ����� ������
	int _characterPosX = 11;	// ĳ������ ��ǥ
	int _characterPosY = 8;
	int _offsetPosX = 0;		// ĳ���� �̵���. ������. �̵� ����
	int _offsetPosY = 0;
	int _boxPosX = BOX;
	int _boxPosY = BOX;
	int _keyInput = 0;			// Ű �Է�

	MakeDestination();

	PlaySound("SokobanGameBGM.wav", NULL, SND_ASYNC | SND_LOOP);
	/// ���⼭���� ���ӷ��� ����
	while (true)
	{
		DrawUI();

		///�Է�
		//Ű�Է�, �׿� ���� �̵� ���� ������ش�.
		_keyInput = KeyInput();

		//�������� ���� ���ؼ�, Ű �Է��� ���� ���� �Ʒ��� �������� �ʴ´�.
		///if (_keyInput == KEY_NONE) continue;

		switch (_keyInput)
		{
		case KEY_LEFTMOVE: {_offsetPosX = -1; } break;
		case KEY_RIGHTMOVE: {_offsetPosX = 1; } break;
		case KEY_DOWNMOVE: {_offsetPosY = 1; } break;
		case KEY_UPMOVE: {_offsetPosY = -1; } break;

		default:
		{
			_offsetPosX = 0;
			_offsetPosY = 0;
		}
		break;
		}

		/// ����
		// ĳ������ �̵��� ó��
		if (CheckCharacterMove(_characterPosX, _characterPosY, _offsetPosX, _offsetPosY) == true)
		{
			// �̵� ���� - �̵���Ű��.
			_characterPosX += _offsetPosX;

			// �̵� �� �� offsetPosX �� �ٽ� Ű, ���� Ű�Է� �ް� ++
			if (_offsetPosX == 0)
			{

			}
			else if (_offsetPosX++)
			{
				g_CharNumMove++;
			}

			// �̵� �� �� offsetPosX �� �ٽ� Ű, ���� Ű�Է� �ް� ++
			_characterPosY += _offsetPosY;

			if (_offsetPosY == 0)
			{

			}
			else if (_offsetPosY++)
			{
				g_CharNumMove++;
			}
		}
		else
		{
			// �̵� �Ұ� - �ƹ� �͵� ���� �ʴ´�.
		}

		// ������ ����
		Sleep(110);

		/// �׸���
		// �������� ��� �׸���.
		DrawAll();

		// (���� �� ����) ���� ĳ���͸� �׸���.
		DrawCharacter(_characterPosX, _characterPosY);

		// ������ ������, ���������� �ȴ�.
		if (isEnd())
		{
			// ���� Ÿ��Ʋ �����ֱ�
			GameEndTitle();

			/// �����ϱ� �޴� 1�� �ٽ��ϱ� �۵� ����(�ʱ�ȭ �ȵ�)
			if (EndMain() == true)
			{
				system("cls");
			}
		}
	}
	return 0;
}
