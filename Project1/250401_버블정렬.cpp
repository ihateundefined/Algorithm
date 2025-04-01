#include <stdio.h>
#include <string.h>

void swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(char * ar, int size)
{
	// 전체에 대해서 정렬 반복
	for (int i = 0; i < size - 1; i++) {
		// 한 회기 당 가장 큰 문자 뒤로 보내기
		for (int j = 1; j < size - i; j++) {
			if (ar[j - 1] > ar[j]) {
				swap(&ar[j - 1], &ar[j]);
			}
		}
		// 1차 정렬 완료 후 ... w만 맨 뒤로 감
		printf("%d차 정렬 후 문자열 : %s\n", i + 1, ar);
	}
}

void main()
{
	char str[] = "winapi";

	int len = strlen(str);

	printf("정렬 전 문자열 : %s\n", str);

	BubbleSort(str, len);

	printf("버블 정렬 완료 후 문자열 : %s\n", str);
}