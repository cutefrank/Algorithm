// QuickSort.cpp : 定義主控台應用程式的進入點。
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
	srand((unsigned)time(NULL)); //有空看一下這行

	int number[MAX] = { 0 }; //將陣列清空

	printf("排序前："); //印出字串

	int i; //宣告在外面，就不用重複宣告

	//印出排序前數字
	for (i = 0; i < MAX; i++) {
		number[i] = rand() % 100;
		printf("%d ", number[i]);
	}
	
	quickSort(number, 0, MAX - 1);//快速排序法

	printf("\r\n排序後：");

	//印出排序後數字
	for (i = 0; i < MAX; i++)
		printf("%d ", number[i]);

	printf("\r\n"); //換行

	system("PAUSE");//讓視窗持續顯示
	return 0;
}

//快速排序實作
void quickSort(int number[], int left, int right) {
	if (left < right) {
		int s = number[(left + right) / 2];
		int i = left - 1;
		int j = right + 1;

		while (1) {
			while (number[++i] < s);  // 向右找 
			while (number[--j] > s);  // 向左找 
			if (i >= j)
				break;
			SWAP(number[i], number[j]);
		}

		quickSort(number, left, i - 1);   // 對左邊進行遞迴 
		quickSort(number, j + 1, right);  // 對右邊進行遞迴 
	}
}

