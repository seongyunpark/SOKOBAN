//콘솔 그래픽 라이브러리
#include "ConsoleLib.h"
//소코반 관련
#include "sokoban.h"
#include "Title_End_.h"
#include "windows.h"
#include <stdlib.h>
#include "playsoundapi.h"

int g_CharNumMove = 0;

///메인 함수 시작
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


	/// 초기화
	if (Initialize() == FALSE)
	{
		return 0;
	}

	///콘솔 창의 타이틀 변경
	SetConsoleTitle("쏘코반!");

	///커서 사이즈 변경...?
	LHSetCursor(20, FALSE);

	/// 스크린 사이즈 변경
	set_screen_size(60, 30);

	/// 소코반 시작

	//초기화(게임 시작 후, 단 한번만 일어나야 하는 것)
	//InitGameBoard();

	/// 소코반(클래스)에서 사용할 변수들
	int _characterPosX = 11;	// 캐릭터의 좌표
	int _characterPosY = 8;
	int _offsetPosX = 0;		// 캐릭터 이동값. 오프셋. 이동 벡터
	int _offsetPosY = 0;
	int _boxPosX = BOX;
	int _boxPosY = BOX;
	int _keyInput = 0;			// 키 입력

	MakeDestination();

	PlaySound("SokobanGameBGM.wav", NULL, SND_ASYNC | SND_LOOP);
	/// 여기서부터 게임루프 시작
	while (true)
	{
		DrawUI();

		///입력
		//키입력, 그에 따른 이동 값을 만들어준다.
		_keyInput = KeyInput();

		//깜빡임을 막기 위해서, 키 입력이 없을 때는 아래를 진행하지 않는다.
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

		/// 연산
		// 캐릭터의 이동을 처리
		if (CheckCharacterMove(_characterPosX, _characterPosY, _offsetPosX, _offsetPosY) == true)
		{
			// 이동 가능 - 이동시키자.
			_characterPosX += _offsetPosX;

			// 이동 할 때 offsetPosX 가 핵심 키, 가로 키입력 받고 ++
			if (_offsetPosX == 0)
			{

			}
			else if (_offsetPosX++)
			{
				g_CharNumMove++;
			}

			// 이동 할 때 offsetPosX 가 핵심 키, 세로 키입력 받고 ++
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
			// 이동 불가 - 아무 것도 하지 않는다.
		}

		// 프레임 제어
		Sleep(110);

		/// 그리기
		// 게임판을 모두 그린다.
		DrawAll();

		// (게임 판 위에) 현재 캐릭터를 그린다.
		DrawCharacter(_characterPosX, _characterPosY);

		// 게임이 끝나면, 빠져나오게 된다.
		if (isEnd())
		{
			// 엔딩 타이틀 보여주기
			GameEndTitle();

			/// 새로하기 메뉴 1번 다시하기 작동 오류(초기화 안됨)
			if (EndMain() == true)
			{
				system("cls");
			}
		}
	}
	return 0;
}
