#include<iostream>
#include<windows.h>
using namespace std;

int main() {
	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout,&csbi);
	while(true) 
	for(int i=0x00;i<0xFF;i++){
		SetConsoleTextAttribute(hstdout,i);
		cout<<i<<"	"; 
	}
	return 0;
}
