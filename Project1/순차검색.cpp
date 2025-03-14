/*
* [�����˻�]
* �־��� �迭���� key���� 75�� ���� �˻��ϴ� �˰����� �ۼ�
* ��, �˻� �˰����� �Լ��� �ۼ�
* ���� ã�Ҵٸ� "ã�� ���� ?��°�� �ֽ��ϴ�."��� ���
* ã�� ���� ���ٸ� "���� ã�� �� �����ϴ�."��� ���
* 
* int ar[]={23,47,19,63,57,26,75,73,82,89,47,11};
* key=75;
*/

#include <stdio.h>

int LinearSearch(int* pArr, int nSize, int nKey)
{
	for (int i = 0; i < nSize; i++)
	{
		if (nKey == pArr[i])
		{
			return i;
		}
	}
	return -1;
}

void main()
{
	int ar[] = { 23, 47, 19, 63, 57, 26, 75, 73, 82, 89, 47, 11 };
	int key = 75;
	int size = sizeof(ar) / sizeof(ar[0]);

	int idx = LinearSearch(ar, size, key);

	if (idx == -1) {
		printf("ã�� ���� �����ϴ�\n");
	}
	else {
		printf("ã�� ���� %d ��°�� �ֽ��ϴ�\n", idx + 1);
	}	
}