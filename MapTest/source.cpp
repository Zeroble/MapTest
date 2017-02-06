#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

typedef struct g_Player{
	int x = 1;
	int y = 0;
};
g_Player player;


void gotoxy(int x, int y) {
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

int main() {
	clock_t CurTime, OldTime;
	OldTime = clock();
	char nKey;

	int map[11][21] = {
		1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,
		1,0,1,1,0,1,0,1,1,1,0,0,1,0,1,1,1,1,0,1,1,
		1,0,1,0,0,1,0,0,0,1,1,0,0,0,1,0,1,0,0,1,1,
		1,0,1,1,1,1,1,1,0,0,1,1,1,0,0,0,1,0,1,1,1,
		1,0,0,1,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,1,
		1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,0,1,0,1,
		1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1,0,1,
		1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 };

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 21; j++) {
			if (map[i][j] == 1) printf("■");
			else printf("□");
		}
		printf("\n");
	}

	while (1) {
			CurTime = clock();

			if (_kbhit()){
				nKey = _getch();
				gotoxy(player.x*2, player.y);
				printf("□");
				switch (nKey){
				case '8': //위
					if (map[player.y-1][player.x ] == 0) {
						player.y--;
					}
					break;

				case '4': //왼쪽
					if (map[player.y][player.x-1] == 0) {
						player.x--;
					}
					break;

				case '6':  //오른쪽
					if (map[player.y][player.x+1] == 0) {
						player.x++;
					}
					break;
				
				case '5':  //아래
					if (map[player.y+1][player.x ] == 0) {
						player.y++;
					}
					break;
				}
			}
			gotoxy(player.x*2,player.y);
			printf("◆");

			gotoxy(60,15);
			printf("%d,%d",player.x,player.y);

			while (1)
			{
				CurTime = clock();
				if (CurTime - OldTime > 33) {
					OldTime = CurTime;
					break;
				}
			}
			if (player.x == 19 && player.y == 10) break;
		}
	system("cls");
	printf("YOU WIN!");
	system("PAUSE");
}