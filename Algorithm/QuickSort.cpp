// QuickSort.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include "stdio.h" 
#include "stdlib.h" 
#include "time.h" 
#define MAX 10 
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

void quickSort(int[], int, int);

int main(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL)); //���Ŭݤ@�U�o��

	int number[MAX] = { 0 }; //�N�}�C�M��

	printf("�Ƨǫe�G"); //�L�X�r��

	int i; //�ŧi�b�~���A�N���έ��ƫŧi

	//�L�X�Ƨǫe�Ʀr
	for (i = 0; i < MAX; i++) {
		number[i] = rand() % 100;
		printf("%d ", number[i]);
	}
	
	quickSort(number, 0, MAX - 1);//�ֳt�ƧǪk

	printf("\r\n�Ƨǫ�G");

	//�L�X�Ƨǫ�Ʀr
	for (i = 0; i < MAX; i++)
		printf("%d ", number[i]);

	printf("\r\n"); //����

	system("PAUSE");//�������������
	return 0;
}

//�ֳt�Ƨǹ�@
void quickSort(int number[], int left, int right) {
	if (left < right) {
		int s = number[(left + right) / 2];
		int i = left - 1;
		int j = right + 1;

		while (1) {
			while (number[++i] < s);  // �V�k�� 
			while (number[--j] > s);  // �V���� 
			if (i >= j)
				break;
			SWAP(number[i], number[j]);
		}

		quickSort(number, left, i - 1);   // �索��i�滼�j 
		quickSort(number, j + 1, right);  // ��k��i�滼�j 
	}
}

