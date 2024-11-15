//2d_arr_pt.c
#include <stdio.h>

#define ROWS 3
#define COLS 5

void printArr(char arr[ROWS][COLS]) {
	//printf("배열의 상태:\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	//RowXCol크기의 2차원 배열 선언하기
	char data[ROWS][COLS] = { 0 };//모든 요소를 0으로 초기화
	char(*p)[COLS];//COLS개의 char을 가지는 배열을 가르키는 포인터

	p = data;//포인터 p가 data배열을 가르키도록 설정

	//포인터를 사용하여 배열의 요소에 값할당
	(*p)[1] = 3;//첫 번째 행의 두번째 요소에 3할당
	(*(p + 1))[2] = 4;//두 번째 행의 세번쨰 요소에 4할당
	(*(p + 1))[4] = 5;

	printf("초기 배열의 상태:\n");
	printArr(data);

	p = data;//포인터p를 다시 첫번째행으로 초기화
	p++;//두번째행으로 이동
	(*p)[0] = 7;//(2,1)
	(*(p - 1))[3] = 8;//(1,3)

	printf("두번째 수정 후 배열의 상태:\n");
	printArr(data);

	//포인터 산술 연산을 사용함
	char* ptr = &data[0][0];//(1,1)
	*(ptr + 6) = 10;//(1,1) -> (2,2) 3행 5열 즉, (0,0)에서 오른쪽으로 6번이동
	*(ptr + 10) = 11;//(1,1) -> (3,1) 
	*(ptr + 14) = 28;//(1,1) -> (3,5) 
	//*(ptr+15)이후부터는 행렬 크기 초과
	printf("포인터 산술 연산 후 배열의 상태:\n");
	printArr(data);


	//첫번째행과 세번째행 바꾸기
	char tmp[COLS];
	for (int i = 0; i < COLS; i++) {
		tmp[i] = data[0][i];
		data[0][i] = data[2][i];
		data[2][i] = tmp[i];
	}

	printf("1행과 3행 교환 후 배열의 상태:\n");
	printArr(data);

	return 0;
}