#include "ConsoleLib.h"

// �ڵ��� �������� �� ���̴�. �� ���� ������ ����� �ʴ´�.
HANDLE g_hConsole;


BOOL Initialize()
{
	// �ְܼ��ӿ� �ڵ� ����
	g_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (g_hConsole == INVALID_HANDLE_VALUE)
	{
		printf("Err, INVALID_HANDLE_VALUE\n");

		return FALSE;
	}

	return TRUE;
}

//// ȭ�� ä���
void LHFillScreen(int ch)
{
	int   ix, iy;
	COORD cdPos;

	for (iy = 0; iy < 24; iy++)
	{
		for (ix = 0; ix < 80; ix++)
		{
			cdPos.X = ix;
			cdPos.Y = iy;
			SetConsoleCursorPosition(g_hConsole, cdPos);
			printf("%c", ch);
			//putchar(ch);
		}
	}
}

//// ��ǥ�� ���ڿ� ���
void LHFillScreenEx(const char* pStr)
{
	int   ix, iy;
	COORD cdPos;
	int	  nStrlen = strlen(pStr);

	for (iy = 0; iy < 24; iy++)
	{
		for (ix = 0; ix < 80; ix += nStrlen)
		{
			cdPos.X = ix;
			cdPos.Y = iy;
			SetConsoleCursorPosition(g_hConsole, cdPos);
			printf("%s", pStr);
		}
	}
}

//// Ŀ�� ��ġ ����
void LHLocateCursor(int x, int y)
{
	COORD cdPos = { x, y };

	SetConsoleCursorPosition(g_hConsole, cdPos);
}


//// ��ǥ�� ���� ���
void LHPutChar(int x, int y, char ch)
{
	COORD cdPos = { x, y };

	SetConsoleCursorPosition(g_hConsole, cdPos);
	printf("%c", ch);
	//putchar(ch);
}

//// ��ǥ�� ���� ��� ( �÷��Ӽ�����)
void LHPutAttrChar(int x, int y, char ch, WORD bg, WORD fg)
{
	DWORD dwCharsWritten;
	COORD cdFill = { x, y };
	WORD  wColor = bg | fg;

	FillConsoleOutputAttribute(g_hConsole, wColor, 1, cdFill, &dwCharsWritten);
	FillConsoleOutputCharacter(g_hConsole, ch, 1, cdFill, &dwCharsWritten);
}

//// ��ǥ�� ���ڿ� ��� ( �÷��Ӽ����� )
void LHPutAttrCharEx(int x, int y, const char* pStr, WORD bg, WORD fg)
{
	DWORD dwCharsWritten;
	COORD cdFill = { x, y };
	WORD  wColor = bg | fg;
	int   nStrlen = strlen(pStr);

	FillConsoleOutputAttribute(g_hConsole, wColor, nStrlen, cdFill, &dwCharsWritten);
	WriteConsoleOutputCharacter(g_hConsole, pStr, nStrlen, cdFill, &dwCharsWritten);
}

//// ��ü ���� �÷� �Ӽ� ����
void LHSetAttrChar(WORD bg, WORD fg)
{
	WORD wColor = bg | fg;
	SetConsoleTextAttribute(g_hConsole, wColor);
}

//// Ŀ�� ���� ����
void LHSetCursor(DWORD dwSize, BOOL bVisible)
{
	CONSOLE_CURSOR_INFO curInfo;

	curInfo.bVisible = bVisible;
	curInfo.dwSize = dwSize;
	SetConsoleCursorInfo(g_hConsole, &curInfo);
}
