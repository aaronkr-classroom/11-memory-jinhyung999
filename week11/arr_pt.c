//arr_pt.c
#include <stdio.h>

#define SIZE 10

int main() {
	char data[SIZE] = {
		1,2,3,4,5,6,7,8,9,10
	};

	int result = 0,
		i;
	char* p = data;

	//10번 반복하면서 포인터 p를 사용하여 배열의 각요소를 result 변수에 합산함
	for (i = 0; i < SIZE; i++) {
		printf("result: %d\n",result);
		//포인터가 가르키는 대상의 값을 합산
		result = result + *p;
		//data배열의 다음항목으로 주소 이동
		p++;
	}

	printf("마지막 result 합: %d\n", result);

	return 0;
}