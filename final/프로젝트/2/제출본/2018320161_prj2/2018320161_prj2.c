#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

// Sample code, Project02, COSE101, Spring Semester, 2018
// Computer Science and Engineering, College of Information, Korea University, Seoul.

#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32 
#define p 112 
#define P 80 
#define ESC 27

#define MAP_ADJ_X 10
#define MAP_ADJ_Y 5

#define X 7
#define Y 4

typedef struct _block {
	int pos_x; //position of block
	int pos_y;
	int num;
	int nextnum;
	int isactive;
}Block;
Block block;


/* @ 'DO NOT MODIFY THESE FUNCTIONS.' */
void removeCursorFromCMD();               // These two are cmd control functions.        
void setCoordinate(int x, int y);         // you dont need modify these two functions.  

										  /* display fuctions */
void goMainMenuScreen();         // 메인메뉴로 이동. Moving to main menu.
void printGameScreen();            // 게임화면 출력.   Printing game screen.
void printPauseScreen();         // 일시 정지 화면.   Prining pause screen.
void printEndScreen(int endType);   // 스테이지 종료 화면 출력. 스테이지클리어, 모든스테이지클리어, 패배.
									//Printing result of end of stages including 'cleared the stage', 'cleared whole stages', and 'lost'.
void clearScreen();
/* @ 'DO NOT MODIFY THESE FUNCTIONS.' ends. */

/* @ --- From this line, You can modify all of this part. ---- */
//Implement these functions below. Free to modify anything in this part to complete your project.
/* block control and merging functions  */
int takeBlockControl();            // 블록 조작 방향 입력 받음.   Taking input to move the falling block.
void moveBlock(int direction);      // 입력 받은 방향으로 블록 이동.   Actually Move the falling block to certain setted dirlections for each keys.
int checkAdjacentBlock(int, int);   // 블록 인접 블록숫자 확인.    Checking values of blocks nearby.

									//* game flow control functions */
int checkStageEnd();      // 스테이지가 끝났는지 체크. (스테이지 클리어, 모든 스테이지 클리어, 패배)         Checking condition for end of the stage. (stage clear, all stage clear, lost)
void setGameFlow(int type); // 각 스테이지에 맞는 게임 환경 세팅.   Setting up status values for each stages.

int getRandomNumber();   // 랜덤 넘버 생성. Generating new random number.
void newBlock();      // 새 블록을 만듦. Making new block. 

int checkgameover();

int time_interval_moveBlockDown;
int goal;
int currentStage = 0;
int score;
int best_score = 0;
int gameScreen[X][Y] = { 0 };
int next_num = 0;
int judge;

void main() {
	srand(time(NULL));
	removeCursorFromCMD();
	goMainMenuScreen();

	while (1) {
		int judge;
		for (int j = 0; j < 5; j++) {
			if (takeBlockControl() == SPACE) break;
			printGameScreen();
			Sleep(time_interval_moveBlockDown);
		}
		moveBlock(DOWN);
		if (!block.isactive) {// This block is cheking that wether the falling block got touched by floor or other blocks which has same value.
			judge = 1;
			do {
				judge = checkAdjacentBlock(block.pos_x, block.pos_y);
			} while (judge);
			if (checkgameover() == 0)
			{
				printEndScreen(0);
				clearScreen();
			}
			if (checkStageEnd() != 1)
				newBlock();
		}
	}
}

int getRandomNumber() {
	int rannum, ran;

	ran = rand() % 10;
	if (ran >= 0 && ran <= 4) rannum = 2;
	else if (ran >= 5 && ran <= 7) rannum = 4;
	else rannum = 8;

	return rannum;
}

void newBlock() {

	if (next_num == 0) {
		block.num = getRandomNumber();
	}
	else block.num = next_num;

	block.nextnum = getRandomNumber();
	next_num = block.nextnum;

	block.pos_x = 0; // 떨어지기 시작하는 위치는 현재 (0, 1)로 설정되어있습니다. 이 부분도 고쳐서 함수를 완성하세요.
	block.pos_y = rand() % 4; // The initial position is setted as (0, 1) now. You should modify these lines for complete this function.
	block.isactive = 1;
	gameScreen[block.pos_x][block.pos_y] = block.num;
}

int takeBlockControl() {
	int input_blockControl = 0;

	if (_kbhit()) {
		input_blockControl = _getch();
		if (input_blockControl == 224) { // cases for direction keys
			do { input_blockControl = _getch(); } while (input_blockControl == 224);
			switch (input_blockControl) {
			case RIGHT:
				moveBlock(RIGHT);
				break;
			case LEFT:
				moveBlock(LEFT);
				break;
			case DOWN:
				moveBlock(DOWN);
				break;
			default:
				break;
			}
		}
		else {
			switch (input_blockControl) {
			case SPACE:
				judge = 1;
				if (judge == 1) {
					judge = 0;
					while (block.isactive == 1) {
						moveBlock(DOWN);
					}
					judge = 1;
					score += 10;
				}
				break;
			case P:
			case p:
				printPauseScreen();
				break;
			case ESC:
				printEndScreen(0);
				break;
			default:
				break;
			}
		}
	}
	while (_kbhit()) _getch(); //키버퍼를 비움. Emptying key buffer.

	return 0;
}

void moveBlock(int direction) {
	switch (direction) {
	case LEFT:
		if (block.pos_y >0 && gameScreen[block.pos_x][block.pos_y - 1] == 0) {
			gameScreen[block.pos_x][block.pos_y - 1] = block.num;
			gameScreen[block.pos_x][block.pos_y] = 0;
			block.pos_y--;
		}

		break;
	case RIGHT:
		if (block.pos_y < 3 && gameScreen[block.pos_x][block.pos_y + 1] == 0) {
			gameScreen[block.pos_x][block.pos_y + 1] = block.num;
			gameScreen[block.pos_x][block.pos_y] = 0;
			block.pos_y++;
		}

		break;
	case DOWN:
		if (block.pos_x < 6 && gameScreen[block.pos_x + 1][block.pos_y] == 0) {
			gameScreen[block.pos_x + 1][block.pos_y] = block.num;
			gameScreen[block.pos_x][block.pos_y] = 0;
			block.pos_x++;
		}
		else {
			block.isactive = 0;
		}
	}
}

int checkAdjacentBlock(int x, int y) {

	if (x < X - 1 && gameScreen[x][y] == gameScreen[x + 1][y]) {

		score += gameScreen[x][y] * 2;
		gameScreen[x][y] = 0;
		gameScreen[x + 1][y] *= 2;
		
		if (gameScreen[x - 1][y] != 0) {
			for (int i = 1; x - i; i++) {
				gameScreen[x - i + 1][y] = gameScreen[x - i][y];
				gameScreen[x - i][y] = 0;
			}
		}

		block.pos_x++;

		printGameScreen();
		Sleep(200);
		return 1;
	}
	if (y>0 && gameScreen[x][y] == gameScreen[x][y - 1]) {
		score += gameScreen[x][y] * 2;
		gameScreen[x][y] = 0;
		gameScreen[x][y - 1] *= 2;

		if (gameScreen[x - 1][y] != 0) {
			for (int i = 1; x - i; i++) {
				gameScreen[x - i + 1][y] = gameScreen[x - i][y];
				gameScreen[x - i][y] = 0;
			}
		}

		block.pos_y--;

		printGameScreen();
		Sleep(200);
		return 1;
	}
	if (y<3 && gameScreen[x][y] == gameScreen[x][y + 1]) {

		score += gameScreen[x][y] * 2;
		gameScreen[x][y] = 0;
		gameScreen[x][y + 1] *= 2;

		if (gameScreen[x - 1][y] != 0) {
			for (int i = 1; x - i; i++) {
				gameScreen[x - i + 1][y] = gameScreen[x - i][y];
				gameScreen[x - i][y] = 0;
			}
		}
		block.pos_y++;

		printGameScreen();
		Sleep(200);
		return 1;
	}
	else {
		return 0;
	}

	return 0;
}

void setGameFlow(int setGameFlowType) {
	switch (setGameFlowType) {
	case 0:  // 게임 상태 초기화. Initializing the game state
		if (best_score < score)
			best_score = score;

		currentStage = 0;
		score = 0;

	case 1: /* To next stage */
		currentStage++;

		switch (currentStage) {
		case 1:
			time_interval_moveBlockDown = 100;
			goal = 64;
			break;
		case 2:
			time_interval_moveBlockDown = 76;
			goal = 128;
			break;
		case 3:
			time_interval_moveBlockDown = 66;
			goal = 128;
			break;
		case 4:
			time_interval_moveBlockDown = 58;
			goal = 256;
			break;
		case 5:
			time_interval_moveBlockDown = 50;
			goal = 256;
			break;
		case 6:
			time_interval_moveBlockDown = 40;
			goal = 512;
			break;
		case 7:
			time_interval_moveBlockDown = 33;
			goal = 512;
			break;
		case 8:
			time_interval_moveBlockDown = 25;
			goal = 1024;
			break;
		case 9:
			time_interval_moveBlockDown = 20;
			goal = 1024;
			break;
		case 10:
			time_interval_moveBlockDown = 14;
			goal = 2048;
			break;
		}

		if (best_score < score)
			best_score = score;
		score = 0;

		clearScreen();
		newBlock();
		break;

	default:
		clearScreen();
		setCoordinate(MAP_ADJ_X + 2, MAP_ADJ_Y + 13); printf(" @System error: state end condition currupted.");
		exit(0);
	}
}

int checkStageEnd() { // 스테이지가 끝났는지 체크. Checking if the stage is ended.
	for (int i = X - 1; i > 1; i--) {
		for (int j = 0; j < Y; j++) {
			if (gameScreen[i][j] >= goal) {
				currentStage < 10 ? printEndScreen(1) : printEndScreen(2);
				return 1;
			}
		}
	}

	return 0;
}
int checkgameover() {
	for (int i = 0; i < Y; i++) {
		if (gameScreen[0][i] != 0) {
			return 0;
		}
	}
	return 1;
}
/* @ ---- 'You can modify all of this part.' ends. ---- */

/* @ 'DO NOT MODIFY FROM HERE.' */
void removeCursorFromCMD() { // cmd에서 깜빡이는 커서숨김. Concealing cursor from cmd.
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
void setCoordinate(int x, int y) { //cmd에서 커서 위치를 x, y로 세팅.  Setting curser to (x,y).
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void printGameScreen() {
	int i, j, k;

	for (i = 0; i<7; i++) {
		for (j = 0; j<4; j++) {
			setCoordinate(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3));
			if (gameScreen[i][j] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				if (i == 0) {
					setCoordinate(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) - 1);
					printf("             ");
					setCoordinate(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3));
					printf("     ┿      ");
					setCoordinate(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 1);
					printf("             ");
					setCoordinate(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 2);
					printf("-------------");
				}
				else {
					setCoordinate(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3));
					printf("             ");
					setCoordinate(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 1);
					printf("     ┿      ");
					setCoordinate(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 2);
					printf("             ");
				}
			}

			else {
				for (k = 0; k<12;) if (1 << (++k) == gameScreen[i][j]) break;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k + 1);

				if (i == 0) {
					setCoordinate(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) - 1);
					printf("┌─────────┐ ");
					setCoordinate(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3));
					printf("   %4d", gameScreen[i][j]);
					setCoordinate(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 1);
					printf("└─────────┘ ");
					setCoordinate(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 2);

				}
				else {
					setCoordinate(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3));
					printf("┌─────────┐  ");
					setCoordinate(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 1);
					printf("   %4d", gameScreen[i][j]);
					setCoordinate(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 2);
					printf("└─────────┘  ");
				}

			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y); printf(" Stage : %4d", currentStage);
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 1); printf(" GOAL  : %4d", goal);
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 2); printf(" SPEED  : %.1f", 100.0 / (float)time_interval_moveBlockDown);
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 3); printf("+-  N E X T  -+ ");
	for (k = 0; k<12;) if (1 << (++k) == block.nextnum) break;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k + 1);
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 4); printf("  ┌─────────┐    ");
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 5); printf("     %4d    ", block.nextnum);
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 6); printf("  └─────────┘    ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 7); printf("+-- -  -  - --+ ");
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 9); printf(" YOUR SCORE :");
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 10); printf("        %6d", score);
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 11); printf(" BEST SCORE :");
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 12); printf("        %6d", best_score);

	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 14); printf("◁  ▷ : Left / Right");
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 15); printf("  ▽   : Soft Drop ");
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 16); printf(" SPACE : Hard Drop");
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 17); printf("   P   : Pause");
	setCoordinate(MAP_ADJ_X + 28, MAP_ADJ_Y + 18); printf("  ESC  : Quit");
}

void goMainMenuScreen() { // 메인메뉴 출력 함수. Printing out main menu.
	int x = 19;
	int y = 9;
	int input_command = 0;

	setCoordinate(x, y + 2); printf("──────────────────────────────────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("IS ────────────────────────────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("TRIS ─────────────────────────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("TETRIS ────────────────────────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("☆ TETRIS ─────────────────────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("─48 ☆ TETRIS ────────────────────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("── 2048 ☆ TETRIS ─────────────────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("─── 2048 ☆ TETRIS ───────────────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("──── 2048 ☆ TETRIS ──────────────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("─────  2048 ☆ TETRIS ────────────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("───────  2048 ☆ TETRIS ──────────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("────────  2048 ☆ TETRIS ─────────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("─────────  2048 ☆ TETRIS ────────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("──────────  2048 ☆ TETRIS ───────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("───────────  2048 ☆ TETRIS ──────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("────────────  2048 ☆ TETRIS ─────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("─────────────  2048 ☆ TETRIS ────");
	Sleep(30);
	setCoordinate(x, y + 2); printf("──────────────  2048 ☆ TETRIS ───");
	Sleep(30);
	setCoordinate(x, y + 2); printf("───────────────  2048 ☆ TETRIS ──");
	Sleep(30);
	setCoordinate(x, y + 2); printf("────────────────  2048 ☆ TETRIS ─");


	setCoordinate(x + 2, y + 4); printf(" Press any key to start");

	setCoordinate(x, y + 6);  printf(" ▤▤▤▤ HOW TO CONTROL ▤▤▤▤");
	setCoordinate(x, y + 7);  printf(" ▤                            ▤");
	setCoordinate(x, y + 8);  printf(" ▤    ◁  ▷ : Left / Right   ▤");
	setCoordinate(x, y + 9);  printf(" ▤      ▽   : Soft Drop      ▤");
	setCoordinate(x, y + 10); printf(" ▤    SPACE  : Hard Drop      ▤");
	setCoordinate(x, y + 11); printf(" ▤      P    : Pause          ▤");
	setCoordinate(x, y + 12); printf(" ▤     ESC   : Quit           ▤");
	setCoordinate(x, y + 13); printf(" ▤                            ▤");
	setCoordinate(x, y + 14); printf(" ▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");

	setCoordinate(x, y + 16); printf("          ESC: Exit game.     ");



	while (_kbhit())
		_getch();
	input_command = _getch();


	if (input_command == ESC) {
		clearScreen();
		exit(0);
	}
	else
		setGameFlow(0); /* Reset the game */

}
void printPauseScreen() { // 게임 일시정지 Pause game.
	int x = MAP_ADJ_X + 8;
	int y = MAP_ADJ_Y + 5;

	setCoordinate(x, y + 0); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
	setCoordinate(x, y + 1); printf("▤                              ▤");
	setCoordinate(x, y + 2); printf("▤  +-----------------------+   ▤");
	setCoordinate(x, y + 3); printf("▤  |       P A U S E       |   ▤");
	setCoordinate(x, y + 4); printf("▤  +-----------------------+   ▤");
	setCoordinate(x, y + 5); printf("▤   Press any key to resume.   ▤");
	setCoordinate(x, y + 6); printf("▤                              ▤");
	setCoordinate(x, y + 7); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");

	_getch();

	system("cls");
	printGameScreen();
}
int isStageEnd() { // 스테이지가 끝났는지 체크   Checking if stage ended up or not.
	for (int i = X - 1; i > 1; i--) {
		for (int j = 0; j < Y; j++) {
			if (gameScreen[i][j] >= goal) {
				currentStage < 10 ? printEndScreen(1) : printEndScreen(2);
				return 1;
			}
		}
	}

	return 0;
}
void printEndScreen(int endType) {
	int input_command = 0;
	int x = MAP_ADJ_X + 8;

	switch (endType) {
	case 0:
		setCoordinate(x, MAP_ADJ_Y + 5);  printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
		setCoordinate(x, MAP_ADJ_Y + 6);  printf("▤                              ▤");
		setCoordinate(x, MAP_ADJ_Y + 7);  printf("▤  +-----------------------+   ▤");
		setCoordinate(x, MAP_ADJ_Y + 8);  printf("▤  |  G A M E  O V E R..   |   ▤");
		setCoordinate(x, MAP_ADJ_Y + 9);  printf("▤  +-----------------------+   ▤");
		setCoordinate(x, MAP_ADJ_Y + 10); printf("▤   YOUR SCORE: %6d         ▤", score);
		setCoordinate(x, MAP_ADJ_Y + 11); printf("▤                              ▤");
		setCoordinate(x, MAP_ADJ_Y + 12); printf("▤   Press any key to restart.  ▤");
		setCoordinate(x, MAP_ADJ_Y + 13); printf("▤                              ▤");
		setCoordinate(x, MAP_ADJ_Y + 14); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
		setCoordinate(x, MAP_ADJ_Y + 16); printf("      ESC: Back to main menu.     ");

		while (_kbhit()) _getch();
		input_command = _getch();

		if (input_command == ESC) {
			while (_kbhit()) _getch();
			clearScreen();
			goMainMenuScreen();
			return;
		}

		setGameFlow(0); /* Reset the game */
		break;

	case 1:
		setCoordinate(x, MAP_ADJ_Y + 5);  printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
		setCoordinate(x, MAP_ADJ_Y + 6);  printf("▤                              ▤");
		setCoordinate(x, MAP_ADJ_Y + 7);  printf("▤  +-----------------------+   ▤");
		setCoordinate(x, MAP_ADJ_Y + 8);  printf("▤  |      STAGE CLEAR      |   ▤");
		setCoordinate(x, MAP_ADJ_Y + 9);  printf("▤  +-----------------------+   ▤");
		setCoordinate(x, MAP_ADJ_Y + 10); printf("▤   YOUR SCORE: %6d         ▤", score);
		setCoordinate(x, MAP_ADJ_Y + 11); printf("▤                              ▤");
		setCoordinate(x, MAP_ADJ_Y + 12); printf("▤ Press any key to next stage. ▤");
		setCoordinate(x, MAP_ADJ_Y + 13); printf("▤                              ▤");
		setCoordinate(x, MAP_ADJ_Y + 14); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");

		while (_kbhit()) _getch();
		input_command = _getch();

		setGameFlow(1); /* To next stage */
		break;

	case 2:
		setCoordinate(x, MAP_ADJ_Y + 5);  printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
		setCoordinate(x, MAP_ADJ_Y + 6);  printf("▤                                      ▤");
		setCoordinate(x, MAP_ADJ_Y + 7);  printf("▤  +-------------------------------+   ▤");
		setCoordinate(x, MAP_ADJ_Y + 8);  printf("▤  | WINNER WINNER CHICKEN DINNER! |   ▤");
		setCoordinate(x, MAP_ADJ_Y + 9);  printf("▤  +-------------------------------+   ▤");
		setCoordinate(x, MAP_ADJ_Y + 10); printf("▤         YOUR SCORE: %6d           ▤", score);
		setCoordinate(x, MAP_ADJ_Y + 11); printf("▤                                      ▤");
		setCoordinate(x, MAP_ADJ_Y + 12); printf("▤         Cleared final stage.         ▤");
		setCoordinate(x, MAP_ADJ_Y + 13); printf("▤                                      ▤");
		setCoordinate(x, MAP_ADJ_Y + 14); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");

		while (_kbhit()) _getch();
		input_command = _getch();
		setGameFlow(0); /* Reset the game */
		break;

	default:
		clearScreen();
		setCoordinate(x, MAP_ADJ_Y + 13); printf(" @System error: state end condition currupted.");
		exit(0);
	}
}
void clearScreen() {
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			gameScreen[i][j] = 0;
		}
	}
	block.pos_x = 0;
	block.pos_x = 0;
	block.num = 0;
	block.nextnum = 0;
	block.isactive = 0;

	system("cls");
}

/* @ 'DO NOT MODIFY FROM HERE.'ends. */