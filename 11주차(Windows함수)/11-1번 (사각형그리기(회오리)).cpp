// 2017-1 ���α׷��ַ� 11��-1�� gotoxy �� �̿��� ȭ�� ������
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

void gotoxy(int x, int y) { //���� ���ϴ� ��ġ�� Ŀ�� �̵� Windows.h �Լ�
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void textcolor(int fg_color, int bg_color){ // frontground / background ���ڻ�/���� (�Ѵ� 16����)
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), fg_color | bg_color<<4);
}
void removeCursor(void){ // Ŀ���� �Ⱥ��̰� �Ѵ�
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible=0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void showCursor(void){ // Ŀ���� ���̰� �Ѵ� 
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible=1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void cls(int bg_color, int text_color){ // ȭ�� �����
	char cmd[100];
	int cols=80, lines=24;// cols(����) lines(����) consolâ ���� ���� ũ�� ����. 120 80 �� ����.
	system("cls");//ȭ�������
	sprintf(cmd, "COLOR %x%x", bg_color, text_color);//��� �� ���ڻ� ����.
	sprintf(cmd, "mode con: cols=%d lines=%d",cols,lines); // �̶��� �Է��ؾ� ũ�� ���� ��.
	system(cmd);
}
void draw_box(int x1, int y1, int x2, int y2, char ch){// box �׸��� �Լ�, ch ���ڷ� (x1,y1)~(x2,y2) box�� �׸���.
	int x, y;
	for(x=x1; x<=x2; x++){ // �� ���� ���� �߱�
		gotoxy(x,y1);
		putchar(ch);
		Sleep(5); // sleep(100) -> sleep(5) : �ӵ� �� ������.
	}
	for(y=y1; y<=y2; y++){ // ������ ���� ���� �߱�
		gotoxy(x2,y);
		putchar(ch);
		Sleep(5);
	}
	for(x=x2; x>=x1; x--){ // �Ʒ� ���� ���� �߱�
		gotoxy(x,y2);
		putchar(ch);
		Sleep(5); 
	}
	for(y=y2; y>=y1; y--){ // ���� ���� ���� �߱�
		gotoxy(x1,y);
		putchar(ch);
		Sleep(5);
	}
}

void main(){
	int i, x, y;
	char buf[100];
	cls(WHITE,BLACK); // ���� ��� ���ڻ� ��.
	removeCursor(); // Ŀ���� �Ⱥ��̰� �Ѵ�
	gotoxy(21, 11); 
	printf("�Ѽ����б� ��ǻ�Ͱ��к� ���α׷��ַ�");
	draw_box2(0,0,79,22,'*'); // ȭ�鿡 box�� �׸���. = (0,0)���� (79,22)�� *�� �׸���.
	showCursor(); // ����Ŀ���� Ŀ�� ��Ÿ����
		gotoxy(10,20);
		printf("x y ���ڿ�(��ǥ�Է�) : "); // x,y��ǥ�� �Է�
		scanf("%d %d %s", &x, &y, buf);
		gotoxy(x,y);
		printf("%s", buf);
	for (i=0;i<=9;i++) {// i<10 ���� �ϸ� ��� �׸� ������.
	draw_box(1+i,i+1,78-i,21-i,'*'); // �� �׵θ� �� �ȿ� ä���.
	getch(); // � Ű�� �Է¹޾ƾ� for�� �ϳ������. ex)Enter Spacebar
	}
	// �� �� ���� �׸��� ��� �� 2ĭ��
	//cls(WHITE, BLACK);
	//for (i=0;i<=9;i++) {
	//	draw_box2(i*2,i,78-i*2,22-i,"��");
	//	getch();
	//}
	gotoxy(21, 15); // ������ Ŀ�� ��ġ
}
