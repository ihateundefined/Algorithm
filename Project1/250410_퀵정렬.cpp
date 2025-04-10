#include <stdio.h>
#include <string.h>

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort(char* ar, int size)
{
    int left = 0;
    int right = 0;
    char pivot = 0;

    pivot = ar[size - 1];
    left = 0;
    right = size - 2;

    if (size <= 1) {
        return;
    }

    while (true)
    {
        while (ar[left] < pivot) {
            left++;
        }

        while (ar[right] > pivot) {
            right--;
        }

        if (left >= right) {
            break;
        }

        swap(&ar[left], &ar[right]);
    }
    swap(&ar[left], &ar[size -1]);

    QuickSort(ar, left); // 재귀함수
    QuickSort(ar + left + 1, size - left - 1);
}

void main()
{
    char str[] = "greathuman";

    int len = strlen(str);

    printf("정렬 전 문자열 : %s\n", str);

    QuickSort(str, len);

    printf("정렬 완료 후 문자열 : %s\n", str);
}