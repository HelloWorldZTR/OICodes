#include<windows.h>
#include<tchar.h>

HANDLE hOut;
void ShadowWindowLine(TCHAR *str);
void DrawBox(SMALL_RECT rc);

int main(){
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	char s[] = "Display a line of words, and center the window with shadow";
	ShadowWindowLine(_T("Display a line of words, and center the window with shadow"));
	//CloseHandle(hOut);
	//system("pause");
	
	return 0;
}

void ShadowWindowLine(TCHAR *str) {
	  
	  CONSOLE_SCREEN_BUFFER_INFO bInfo;
	  GetConsoleScreenBufferInfo(hOut, &bInfo);
	  
	  int x1 = 0, x2 = 0, y1 = 0, y2 = 0, chNum =  0;
	  chNum = (int)_tcslen(str);
	  x1 = (bInfo.srWindow.Right - bInfo.srWindow.Left - chNum) / 2 - 2;
	  y1 = (bInfo.srWindow.Bottom - bInfo.srWindow.Top) / 2 - 2;
	  x2 = x1 + chNum +4 + chNum % 2;
	  y2 = y1 + 6;
	  
	  WORD att1	= BACKGROUND_INTENSITY;
	  WORD att0	= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE;
	  WORD attText = FOREGROUND_RED | FOREGROUND_INTENSITY;
	  
	  COORD posShadow = {x1 + 1, y1 + 1}, posText = {x1, y1};
	  for(int i = 0; i < 5; i++) {
	  	FillConsoleOutputAttribute(hOut, att1, chNum + 5, posShadow, NULL);
	  	++posShadow.Y;
	  } 
	  
	  for(int i = 0; i < 5; i++) {
	  	FillConsoleOutputAttribute(hOut, att0, chNum + 5, posText, NULL);
	  	++posText.Y;
	  } 
	  posText.X = x1 + 2;
	  posText.Y = y1 + 2;
	  WriteConsoleOutputCharacter (hOut, str, chNum, posText, NULL) ;
	  SMALL_RECT rc = {x1, y1, x2 - 2, y2 - 2};
	  DrawBox(rc);
	  SetConsoleTextAttribute(hOut, bInfo.wAttributes);
	  return;
}

void DrawBox(SMALL_RECT rc) {
	
	TCHAR chBox[6][3] = {_T("©°"), _T("©´"), _T("©¸"), _T("©¼"), _T("©¤"), _T("©¦")};
	COORD pos = {rc.Left, rc.Top};
	
	for(pos.X = rc.Left; pos.X < rc.Right; pos.X+=2) {
		pos.Y = rc.Top;
		WriteConsoleOutputCharacter(hOut, chBox[4], (int)_tcslen(chBox[4]), pos, NULL);
		pos.Y = rc.Bottom;
		WriteConsoleOutputCharacter(hOut, chBox[4], (int)_tcslen(chBox[4]), pos, NULL);
	}
	
	for(pos.Y = rc.Top; pos.Y < rc.Bottom; ++pos.Y) {
		pos.X = rc.Left;
		WriteConsoleOutputCharacter(hOut, chBox[5], (int)_tcslen(chBox[5]), pos, NULL);
		pos.X = rc.Right;
		WriteConsoleOutputCharacter(hOut, chBox[5], (int)_tcslen(chBox[5]), pos, NULL);
	}
	
	pos.X = rc.Left;
	pos.Y = rc.Top;
	WriteConsoleOutputCharacter(hOut, chBox[0], (int)_tcslen(chBox[0]), pos, NULL);
	
	pos.X = rc.Right;
	pos.Y = rc.Top;
	WriteConsoleOutputCharacter(hOut, chBox[1], (int)_tcslen(chBox[1]), pos, NULL);
	
	pos.X = rc.Left;
	pos.Y = rc.Bottom;
	WriteConsoleOutputCharacter(hOut, chBox[2], (int)_tcslen(chBox[2]), pos, NULL);
	
	pos.X = rc.Right;
	pos.Y = rc.Bottom;
	WriteConsoleOutputCharacter(hOut, chBox[3], (int)_tcslen(chBox[3]), pos, NULL);
	return;
}
