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

	//10�� �ݺ��ϸ鼭 ������ p�� ����Ͽ� �迭�� ����Ҹ� result ������ �ջ���
	for (i = 0; i < SIZE; i++) {
		printf("result: %d\n",result);
		//�����Ͱ� ����Ű�� ����� ���� �ջ�
		result = result + *p;
		//data�迭�� �����׸����� �ּ� �̵�
		p++;
	}

	printf("������ result ��: %d\n", result);

	return 0;
}