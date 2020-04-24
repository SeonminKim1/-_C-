// 2017 ���α׷��ַ� - 11�� 3�� (Ű���� �Է�����)
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#define STAR '*'
#define BLANK ' '

#define ESC 0x1b

#define SPECIAL1 0xe0 // Ư��Ű�� 0xe0 + key ������ �����ȴ�.
#define SPECIAL2 0x00 // keypad ��� 0x00 + key �� �����ȴ�.

#define UP  0x48 // Up key�� 0xe0 + 0x48 �ΰ��� ���� ���´�.
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d

#define UP2		'w'
#define DOWN2	's'
#define LEFT2	'a'
#define RIGHT2	'd'

#define WIDTH 80
#define HEIGHT 24

int Delay = 50; // 100 msec delay, �� ���� ���̸� �ӵ��� ��������. // ���ӿ��� ź �ö󰥶����� �ӵ��� �ö󰡴� ��츦 ������.

void removeCursor(void) { // Ŀ���� �Ⱥ��̰� �Ѵ�
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void gotoxy(int x, int y){ //���� ���ϴ� ��ġ�� Ŀ�� �̵�
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);// WIN32API �Լ��Դϴ�. �̰� ���ʿ� �����
}
void putstar(int x, int y, char ch){ // x,y�� �� ������
	gotoxy(x, y);
	putchar(ch);
}
void erasestar(int x, int y){ // x,y�� �� ������. ��������
	gotoxy(x, y);
	putchar(' ');//(BLANK);
}
void main(){
	unsigned char ch; // Ư��Ű 0xe0 �� �Է¹������� unsigned char �� �����ؾ� ��
	int oldx, oldy, newx, newy;
	int keep_moving;
	newx = oldx = 10;
	newy = oldy = 10;
	removeCursor();
	putstar(oldx, oldy, STAR);
	ch = 0; // �ʱⰪ ��������
	keep_moving = 0;
	while (1) {
		if (kbhit() == 1) {  // Ű���尡 ������ ������
			ch = getch(); // key ���� �д´�
			if (ch == ESC)break; // ESC ����� �ߴ�
			else if (ch == SPECIAL1 || ch == SPECIAL2) { // ���� Ư��Ű��� �ΰ� ���ڵ��´�.
													// ���� ��� UP key�� ��� 0xe0 0x48 �ΰ��� ���ڰ� ���´�.
				ch = getch();
				switch (ch) {
				case UP:
				case DOWN:
				case LEFT:
				case RIGHT:
					keep_moving = 1; // ��ŷ.
					break;
				default:keep_moving=0;
				}
			}
			else { // ASWD �̿� �ϴ� ��� // ����� �÷��̾� 1��. �÷��̾� 2�� �� ��쿡 ����ó���ϸ��.
				switch (ch) {
				case UP2:
					ch = UP; keep_moving = 1; break;
				case DOWN2:
					ch = DOWN; keep_moving = 1; break;
				case LEFT2:
					ch = LEFT; keep_moving = 1; break;
				case RIGHT2: 
					ch = RIGHT; keep_moving = 1; break;
				default:keep_moving = 0;
				}
			}
		}
			if(keep_moving) { // �����̰� ������ ���� ������ Delay �� ���ҽ�Ű�� �ӵ��� ��������
				switch (ch) {
				case UP:
					if (oldy>0) // ��ǥ�� ������ �̴ϱ� -1�̸� ������.
						newy = oldy - 1;    // if(oldy>0)newy=oldy-1;break; <- ���� �ȹٲ�����
					else { // ���������� ������ �ݴ�� 1ĭ �̵�.
						ch = DOWN;
						newy = oldy + 1;
					}break;
				case DOWN:
					if (oldy < HEIGHT - 1) //����
						newy = oldy + 1;
					else { // ���������� ������ �ݴ�� �����ؼ� 1ĭ �̵�.
						ch = UP; // �������� ���� �ݴ��
						newy = oldy - 1; // �ݴ�� 1ĭ �̵�.
					}break;
				case LEFT:
					if (oldx > 0) // ����
						newx = oldx - 1;
					else { // ���������� ������ �ݴ�� 1ĭ �̵�.
						ch = RIGHT;
						newy = oldy + 1;
					}break;
				case RIGHT:
					if (oldx < WIDTH - 1) //����
						newx = oldx + 1;
					else { // ���������� ������ �ݴ�� 1ĭ �̵�.
						ch = LEFT;
						newy = oldy - 1;
					}break;
				}
				erasestar(oldx, oldy); // ������ ��ġ�� * �� �����
				putstar(newx, newy, STAR); // ���ο� ��ġ���� * �� ǥ���Ѵ�.
				oldx = newx; // ������ ��ġ�� ����Ѵ�.
				oldy = newy;
				keep_moving = 1; //1:�ѹ��� ����̵�, 0:�ѹ��� ��ĭ���̵�
								 //���°� Ƣ����� ��� keep_moving = 1; 
			}
			Sleep(Delay); // Delay�� ���̸� �ӵ��� ��������.
		}
	}