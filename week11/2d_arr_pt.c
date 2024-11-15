//2d_arr_pt.c
#include <stdio.h>

#define ROWS 3
#define COLS 5

void printArr(char arr[ROWS][COLS]) {
	//printf("�迭�� ����:\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	//RowXColũ���� 2���� �迭 �����ϱ�
	char data[ROWS][COLS] = { 0 };//��� ��Ҹ� 0���� �ʱ�ȭ
	char(*p)[COLS];//COLS���� char�� ������ �迭�� ����Ű�� ������

	p = data;//������ p�� data�迭�� ����Ű���� ����

	//�����͸� ����Ͽ� �迭�� ��ҿ� ���Ҵ�
	(*p)[1] = 3;//ù ��° ���� �ι�° ��ҿ� 3�Ҵ�
	(*(p + 1))[2] = 4;//�� ��° ���� ������ ��ҿ� 4�Ҵ�
	(*(p + 1))[4] = 5;

	printf("�ʱ� �迭�� ����:\n");
	printArr(data);

	p = data;//������p�� �ٽ� ù��°������ �ʱ�ȭ
	p++;//�ι�°������ �̵�
	(*p)[0] = 7;//(2,1)
	(*(p - 1))[3] = 8;//(1,3)

	printf("�ι�° ���� �� �迭�� ����:\n");
	printArr(data);

	//������ ��� ������ �����
	char* ptr = &data[0][0];//(1,1)
	*(ptr + 6) = 10;//(1,1) -> (2,2) 3�� 5�� ��, (0,0)���� ���������� 6���̵�
	*(ptr + 10) = 11;//(1,1) -> (3,1) 
	*(ptr + 14) = 28;//(1,1) -> (3,5) 
	//*(ptr+15)���ĺ��ʹ� ��� ũ�� �ʰ�
	printf("������ ��� ���� �� �迭�� ����:\n");
	printArr(data);


	//ù��°��� ����°�� �ٲٱ�
	char tmp[COLS];
	for (int i = 0; i < COLS; i++) {
		tmp[i] = data[0][i];
		data[0][i] = data[2][i];
		data[2][i] = tmp[i];
	}

	printf("1��� 3�� ��ȯ �� �迭�� ����:\n");
	printArr(data);

	return 0;
}