//rubiks_cube.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 3//길이
#define FACES 6//면

//전역변수 선언
char* colors[FACES] = {
	"white", "red", "blue", "green", "orange", "yellow"
};
char letters[FACES] = { 'W', 'R', 'B', 'G', 'O', 'Y'};
int hexColors[FACES] = {
	0xFFF, 0xF00, 0x00F, 0x0F0, 0xFA0, 0xFF0
};

//3x3x6배열로 큐브상태 정의(6개의 면)
int cube[LENGTH][LENGTH][FACES];

enum PrintMode
{
	STRING,LETTER,HEX
};


void printCube(enum PrintMode mode)
{
	const char* labels[FACES] = {
		"Up","Left","Front","Right","Back","Down"
	};
	for (int i = 0; i < FACES; i++) {
		printf("%s face:\n", labels[i]);
		for (int j = 0; j < LENGTH; j++) {//행
			for (int k = 0; k < LENGTH; k++) {//열
				switch (mode) {
				case STRING:
					printf("%-7s", colors[cube[i][j][k]]);
					break;

				case LETTER:
					printf("%c", letters[cube[i][j][k]]);
					break;

				case HEX:
					printf("%#05X", hexColors[cube[i][j][k]]);
					break;
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}

void rotateFace(int face) {
	int temp[LENGTH][LENGTH];
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			temp[i][j] = cube[face][i][j];
		}
	}
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			cube[face][j][2-i] = cube[i][j];
		}
	}
}

//큐브 섞기
void scrambleCube() {
	printf("scrambling...");
	srand(time(0));
	for (int i = 0; i < 15; i++) {
		int face = rand() % FACES;
		switch (face)
		{
		case 0: rotateFace(0); printf("U "); break;
		case 1: rotateFace(1); printf("L "); break;
		case 2: rotateFace(2); printf("F "); break;
		case 3: rotateFace(3); printf("R "); break;
		case 4: rotateFace(4); printf("B "); break;
		case 5: rotateFace(5); printf("D "); break;
		}
	}
}

void rotateRight() {
	int temp[LENGTH];
	for (int i = 0; i < LENGTH; i++)temp[i] = cube[3][i][2];
	for (int i = 0; i < LENGTH; i++)cube[3][i][2] = cube[0][2][2-i];
	for (int i = 0; i < LENGTH; i++)cube[0][2][2 - i] = cube[1][2-i][0];
	for (int i = 0; i < LENGTH; i++)cube[1][i][0] = cube[5][0][i];
	for (int i = 0; i < LENGTH; i++)cube[5][0][i] = temp[i];


}
void easyscrambleCube() {
	printf("scrambling...");
	for (int i = 0; i < 5; i++) {
		rotateRight();
	}
}

int main() {
	//초기화
	intiCube();
	printf("Initial Cube:\n");
	printCube(STRING);
	
	//섞기
	for (int i = 1; i <= 4; i++) {
		easyscrambleCube();
		printCube(LETTER);
	}
}