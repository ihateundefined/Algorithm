#include <stdio.h>
#include <string.h>

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(char* ar, int size)
{
    int minidx = 0;

    for (int i = 0; i < size - 1; i++) {
        minidx = i;

        for (int j = i + 1; j < size; j++) {
            if (ar[minidx] > ar[j]) {
                minidx = j;
            }
        }

        if (minidx != i) {
            swap(&ar[i], &ar[minidx]);
        }
    }
}

void main()
{
    char str[] = "winapi";

    int len = strlen(str);

    printf("정렬 전 문자열 : %s\n", str);

    SelectionSort(str, len);

    printf("정렬 완료 후 문자열 : %s\n", str);
}