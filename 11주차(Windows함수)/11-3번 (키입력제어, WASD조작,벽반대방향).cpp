// 2017 프로그래밍랩 - 11주 3번 (키보드 입력제어)
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#define STAR '*'
#define BLANK ' '

#define ESC 0x1b

#define SPECIAL1 0xe0 // 특수키는 0xe0 + key 값으로 구성된다.
#define SPECIAL2 0x00 // keypad 경우 0x00 + key 로 구성된다.

#define UP  0x48 // Up key는 0xe0 + 0x48 두개의 값이 들어온다.
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d

#define UP2		'w'
#define DOWN2	's'
#define LEFT2	'a'
#define RIGHT2	'd'

#define WIDTH 80
#define HEIGHT 24

int Delay = 50; // 100 msec delay, 이 값을 줄이면 속도가 빨라진다. // 게임에서 탄 올라갈때마다 속도가 올라가는 경우를 제어함.

void removeCursor(void) { // 커서를 안보이게 한다
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void gotoxy(int x, int y){ //내가 원하는 위치로 커서 이동
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);// WIN32API 함수입니다. 이건 알필요 없어요
}
void putstar(int x, int y, char ch){ // x,y에 별 보여줌
	gotoxy(x, y);
	putchar(ch);
}
void erasestar(int x, int y){ // x,y에 별 지워줌. 공백으로
	gotoxy(x, y);
	putchar(' ');//(BLANK);
}
void main(){
	unsigned char ch; // 특수키 0xe0 을 입력받으려면 unsigned char 로 선언해야 함
	int oldx, oldy, newx, newy;
	int keep_moving;
	newx = oldx = 10;
	newy = oldy = 10;
	removeCursor();
	putstar(oldx, oldy, STAR);
	ch = 0; // 초기값 정지상태
	keep_moving = 0;
	while (1) {
		if (kbhit() == 1) {  // 키보드가 눌려져 있으면
			ch = getch(); // key 값을 읽는다
			if (ch == ESC)break; // ESC 누루면 중단
			else if (ch == SPECIAL1 || ch == SPECIAL2) { // 만약 특수키라면 두개 문자들어온다.
													// 예를 들어 UP key의 경우 0xe0 0x48 두개의 문자가 들어온다.
				ch = getch();
				switch (ch) {
				case UP:
				case DOWN:
				case LEFT:
				case RIGHT:
					keep_moving = 1; // 마킹.
					break;
				default:keep_moving=0;
				}
			}
			else { // ASWD 이용 하는 경우 // 현재는 플레이어 1명. 플레이어 2명 일 경우에 각자처럼하면됨.
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
			if(keep_moving) { // 움직이고 있으면 벽을 만날때 Delay 를 감소시키면 속도가 빨라진다
				switch (ch) {
				case UP:
					if (oldy>0) // 좌표가 역으로 이니까 -1이면 증가임.
						newy = oldy - 1;    // if(oldy>0)newy=oldy-1;break; <- 방향 안바꿔질때
					else { // 벽을만나면 방향을 반대로 1칸 이동.
						ch = DOWN;
						newy = oldy + 1;
					}break;
				case DOWN:
					if (oldy < HEIGHT - 1) //벽면
						newy = oldy + 1;
					else { // 벽을만나면 방향을 반대로 변경해서 1칸 이동.
						ch = UP; // 벽만나서 방향 반대로
						newy = oldy - 1; // 반대로 1칸 이동.
					}break;
				case LEFT:
					if (oldx > 0) // 벽면
						newx = oldx - 1;
					else { // 벽을만나면 방향을 반대로 1칸 이동.
						ch = RIGHT;
						newy = oldy + 1;
					}break;
				case RIGHT:
					if (oldx < WIDTH - 1) //벽면
						newx = oldx + 1;
					else { // 벽을만나면 방향을 반대로 1칸 이동.
						ch = LEFT;
						newy = oldy - 1;
					}break;
				}
				erasestar(oldx, oldy); // 마지막 위치의 * 를 지우고
				putstar(newx, newy, STAR); // 새로운 위치에서 * 를 표시한다.
				oldx = newx; // 마지막 위치를 기억한다.
				oldy = newy;
				keep_moving = 1; //1:한번에 계속이동, 0:한번에 한칸씩이동
								 //벽맞고 튀어나오는 경우 keep_moving = 1; 
			}
			Sleep(Delay); // Delay를 줄이면 속도가 빨라진다.
		}
	}