// 2017-1 프로그래밍랩 11주-2번 글자색, 배경색 변경
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
// 색상 정의
#define BLACK	0
#define BLUE1	1
#define GREEN1	2
#define CYAN1	3
#define RED1	4
#define MAGENTA1 5
#define YELLOW1	6
#define GRAY1	7
#define GRAY2	8
#define BLUE2	9
#define GREEN2	10
#define CYAN2	11
#define RED2	12
#define MAGENTA2 13
#define YELLOW2	14
#define WHITE	15

#define ESC	0x1b // ESC key 아스키코드 값 // 게임하다가 esc누르면 종료.
void gotoxy(int x, int y){ //내가 원하는 위치로 커서 이동
	COORD pos; 
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void textcolor(int fg_color, int bg_color){ //글자색 , 글자배경색만 바꿔줌.
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), fg_color | bg_color<<4);
}

void showCursor(void){ // 커서를 보이게 한다
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible=1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void cls(int bg_color, int text_color){ 
	char cmd[100];
	system("cls"); // 화면 초기화
	sprintf(cmd, "COLOR %x%x", bg_color, text_color); // 배경색 글자색 변경
	system(cmd);
}
void draw_box(int x1, int y1, int x2, int y2, char ch){
	int x, y;
	for(x=x1; x<=x2; x++){ // 가로 직선 긋기
		gotoxy(x,y1);
		putchar(ch);
		gotoxy(x,y2);
		putchar(ch);
		Sleep(5);
	}
		for(y=y1; y<=y2; y++){ // 세로 직선 긋기
		gotoxy(x1,y);
		putchar(ch);
		gotoxy(x2,y);
		putchar(ch);
		Sleep(5);
	}
}
void main(){
	int bg_color, fg_color;
	char ch;
	removeCursor();
	for (bg_color=0;bg_color<16;bg_color++) {
		fg_color = 15 - bg_color;
		cls(bg_color, fg_color); // 화면 전체 배경색과 글자색을 정한다
		gotoxy(30,11);
		printf("배경색=%d 글자색=%d", bg_color, fg_color);
		ch = getch(); // Enter Key 대신 아무키나 누르면 진행된다
		if (ch==ESC)break; // ESC 누르면 중단
	}
	cls(15, 0); // 화면을 지우기.
	for (bg_color=0;bg_color<=0xf;bg_color++) {//0xf=16
		gotoxy(16,bg_color+4);
		for (fg_color=0;fg_color<=0xf;fg_color++) {
			textcolor(fg_color, bg_color); // 화면색과 관계없이 글자색을 변경한다
			printf(" %x ", fg_color);
		}
		ch = getch(); // Enter Key 대신 아무키나 누르면 진행된다
		if (ch==ESC)break; // ESC 누루면 중단
	}
	gotoxy(0,0);
	cls(WHITE, BLACK);
	getch();
	gotoxy(21, 11);
	textcolor(RED2,CYAN2); // 글자색,음영색
	printf("한성대학교 컴퓨터공학과 프로그래밍랩");
	
	textcolor(WHITE,CYAN2);
	draw_box(0,0,79,22,'*'); // 화면에 box를 그린다.
	gotoxy(21,15);
	
	textcolor(RED2,YELLOW2); // 검은색 글자에 흰색 배경.
}