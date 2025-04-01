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
	// ��ü�� ���ؼ� ���� �ݺ�
	for (int i = 0; i < size - 1; i++) {
		// �� ȸ�� �� ���� ū ���� �ڷ� ������
		for (int j = 1; j < size - i; j++) {
			if (ar[j - 1] > ar[j]) {
				swap(&ar[j - 1], &ar[j]);
			}
		}
		// 1�� ���� �Ϸ� �� ... w�� �� �ڷ� ��
		printf("%d�� ���� �� ���ڿ� : %s\n", i + 1, ar);
	}
}

void main()
{
	char str[] = "winapi";

	int len = strlen(str);

	printf("���� �� ���ڿ� : %s\n", str);

	BubbleSort(str, len);

	printf("���� ���� �Ϸ� �� ���ڿ� : %s\n", str);
}