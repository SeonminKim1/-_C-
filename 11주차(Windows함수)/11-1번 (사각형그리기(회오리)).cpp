// 2017-1 프로그래밍랩 11주-1번 gotoxy 를 이용한 화면 디자인
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

void gotoxy(int x, int y) { //내가 원하는 위치로 커서 이동 Windows.h 함수
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void textcolor(int fg_color, int bg_color){ // frontground / background 글자색/배경색 (둘다 16진수)
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), fg_color | bg_color<<4);
}
void removeCursor(void){ // 커서를 안보이게 한다
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible=0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void showCursor(void){ // 커서를 보이게 한다 
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible=1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void cls(int bg_color, int text_color){ // 화면 지우고
	char cmd[100];
	int cols=80, lines=24;// cols(가로) lines(세로) consol창 가로 세로 크기 조정. 120 80 도 가능.
	system("cls");//화면지우기
	sprintf(cmd, "COLOR %x%x", bg_color, text_color);//배경 및 글자색 변경.
	sprintf(cmd, "mode con: cols=%d lines=%d",cols,lines); // 이라인 입력해야 크기 조정 됨.
	system(cmd);
}
void draw_box(int x1, int y1, int x2, int y2, char ch){// box 그리기 함수, ch 문자로 (x1,y1)~(x2,y2) box를 그린다.
	int x, y;
	for(x=x1; x<=x2; x++){ // 윗 가로 직선 긋기
		gotoxy(x,y1);
		putchar(ch);
		Sleep(5); // sleep(100) -> sleep(5) : 속도 더 빨라짐.
	}
	for(y=y1; y<=y2; y++){ // 오른쪽 세로 직선 긋기
		gotoxy(x2,y);
		putchar(ch);
		Sleep(5);
	}
	for(x=x2; x>=x1; x--){ // 아래 가로 직선 긋기
		gotoxy(x,y2);
		putchar(ch);
		Sleep(5); 
	}
	for(y=y2; y>=y1; y--){ // 왼쪽 세로 직선 긋기
		gotoxy(x1,y);
		putchar(ch);
		Sleep(5);
	}
}

void main(){
	int i, x, y;
	char buf[100];
	cls(WHITE,BLACK); // 배경색 흰색 글자색 블랙.
	removeCursor(); // 커서를 안보이게 한다
	gotoxy(21, 11); 
	printf("한성대학교 컴퓨터공학부 프로그래밍랩");
	draw_box2(0,0,79,22,'*'); // 화면에 box를 그린다. = (0,0)부터 (79,22)를 *로 그린다.
	showCursor(); // 깜빡커리는 커서 나타내줌
		gotoxy(10,20);
		printf("x y 문자열(좌표입력) : "); // x,y좌표를 입력
		scanf("%d %d %s", &x, &y, buf);
		gotoxy(x,y);
		printf("%s", buf);
	for (i=0;i<=9;i++) {// i<10 으로 하면 가운데 항목도 지워짐.
	draw_box(1+i,i+1,78-i,21-i,'*'); // 맨 테두리 외 안에 채우기.
	getch(); // 어떤 키를 입력받아야 for문 하나진행됨. ex)Enter Spacebar
	}
	// □ 로 벽을 그리는 경우 예 2칸씩
	//cls(WHITE, BLACK);
	//for (i=0;i<=9;i++) {
	//	draw_box2(i*2,i,78-i*2,22-i,"□");
	//	getch();
	//}
	gotoxy(21, 15); // 끝나는 커서 위치
}
