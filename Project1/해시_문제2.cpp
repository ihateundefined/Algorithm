/*
* ���� ����
* 11 22 54 64 78 99
*  
* �浹 �߻� ��, �� �����͸� ������ ���� �ٸ� ��Ŷ�� ��������
* �浹�� �߻��ϸ�, ������ ��Ŷ�� �����ϰ�
* �� �� ��Ŷ�� �� ������ �� ������ ��Ŷ�� ä�� ����
* 
* 54, 64�� ���� ��� �� �� ������?
*/

#include <stdio.h>
#include <string.h>

#define BK 10
#define SL 1

int hashtable[BK][SL];

int Hash(int nKey) {
    return nKey % 10;
}

void InsertValue(int nKey)
{
	int bucket = Hash(nKey);

	if (hashtable[bucket][0] == 0)
	{
		hashtable[bucket][0] = nKey;
	}
}

int FindValue(int nKey)
{
	int bucket = Hash(nKey);
	return (hashtable[bucket][0] == nKey);
}

void main()
{
	int key = 0;
	memset(hashtable, 0, sizeof(hashtable));

	for (int i = 0; i < 5; i++)
	{
		printf("%d��° ���� �Է��ϼ��� >> ", i + 1);
		scanf_s("%d", &key);
		InsertValue(key);
	}

	printf("�˻��� Ű�� �Է��ϼ��� >> ");
	scanf_s("%d", &key);

	if (FindValue(key)) {
		printf("�˻��Ǿ����ϴ�!\n");
	}
	else {
		printf("�˻������ʾҽ��ϴ�!\n");
	}
}