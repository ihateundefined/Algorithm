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
#define SL 4

int hashtable[BK][SL];

int Hash(int nKey) {
    return nKey % 10;
}

void InsertValue(int nKey)
{
	int bucket = Hash(nKey);

	// ������ ���Ը��� ����ִ��� Ȯ���ϰ�, ���� �־��ش�
	// for�� ���
	for (int i = 0; i < SL; i++)
	{
		if (hashtable[bucket][i] == 0)
		{
			hashtable[bucket][i] = nKey;
			break;
		}
	}
}

int FindValue(int nKey)
{
	int bucket = Hash(nKey);
	for (int i = 0; i < SL; i++)
	{
		if (hashtable[bucket][i] == nKey)
		{
			// ��ġ�ϸ� 1 true�� return
			return 1;
		}
	}
	// �׷��� ������ 0�� return
	return 0;
}

void main()
{
	int key = 0;
	memset(hashtable, 0, sizeof(hashtable));

	for (int i = 0; i < SL; i++)
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