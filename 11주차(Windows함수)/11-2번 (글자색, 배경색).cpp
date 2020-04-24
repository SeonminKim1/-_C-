// 2017-1 ���α׷��ַ� 11��-2�� ���ڻ�, ���� ����
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
// ���� ����
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

#define ESC	0x1b // ESC key �ƽ�Ű�ڵ� �� // �����ϴٰ� esc������ ����.
void gotoxy(int x, int y){ //���� ���ϴ� ��ġ�� Ŀ�� �̵�
	COORD pos; 
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void textcolor(int fg_color, int bg_color){ //���ڻ� , ���ڹ����� �ٲ���.
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), fg_color | bg_color<<4);
}

void showCursor(void){ // Ŀ���� ���̰� �Ѵ�
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible=1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void cls(int bg_color, int text_color){ 
	char cmd[100];
	system("cls"); // ȭ�� �ʱ�ȭ
	sprintf(cmd, "COLOR %x%x", bg_color, text_color); // ���� ���ڻ� ����
	system(cmd);
}
void draw_box(int x1, int y1, int x2, int y2, char ch){
	int x, y;
	for(x=x1; x<=x2; x++){ // ���� ���� �߱�
		gotoxy(x,y1);
		putchar(ch);
		gotoxy(x,y2);
		putchar(ch);
		Sleep(5);
	}
		for(y=y1; y<=y2; y++){ // ���� ���� �߱�
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
		cls(bg_color, fg_color); // ȭ�� ��ü ������ ���ڻ��� ���Ѵ�
		gotoxy(30,11);
		printf("����=%d ���ڻ�=%d", bg_color, fg_color);
		ch = getch(); // Enter Key ��� �ƹ�Ű�� ������ ����ȴ�
		if (ch==ESC)break; // ESC ������ �ߴ�
	}
	cls(15, 0); // ȭ���� �����.
	for (bg_color=0;bg_color<=0xf;bg_color++) {//0xf=16
		gotoxy(16,bg_color+4);
		for (fg_color=0;fg_color<=0xf;fg_color++) {
			textcolor(fg_color, bg_color); // ȭ����� ������� ���ڻ��� �����Ѵ�
			printf(" %x ", fg_color);
		}
		ch = getch(); // Enter Key ��� �ƹ�Ű�� ������ ����ȴ�
		if (ch==ESC)break; // ESC ����� �ߴ�
	}
	gotoxy(0,0);
	cls(WHITE, BLACK);
	getch();
	gotoxy(21, 11);
	textcolor(RED2,CYAN2); // ���ڻ�,������
	printf("�Ѽ����б� ��ǻ�Ͱ��а� ���α׷��ַ�");
	
	textcolor(WHITE,CYAN2);
	draw_box(0,0,79,22,'*'); // ȭ�鿡 box�� �׸���.
	gotoxy(21,15);
	
	textcolor(RED2,YELLOW2); // ������ ���ڿ� ��� ���.
}