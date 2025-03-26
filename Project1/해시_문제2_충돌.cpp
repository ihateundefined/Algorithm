/*
* 실행 예시
* 11 22 54 64 78 99
*  
* 충돌 발생 시, 이 데이터를 버리지 말고 다른 버킷에 저장하자
* 충돌이 발생하면, 오른쪽 버킷에 저장하고
* 또 그 버킷도 차 있으면 그 오른쪽 버킷에 채워 넣자
* 
* 54, 64의 경우는 어떻게 할 수 있을까?
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

	// 각각의 슬롯마다 비어있는지 확인하고, 값을 넣어준다
	// for문 사용
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
			// 일치하면 1 true를 return
			return 1;
		}
	}
	// 그렇지 않으면 0을 return
	return 0;
}

void main()
{
	int key = 0;
	memset(hashtable, 0, sizeof(hashtable));

	for (int i = 0; i < SL; i++)
	{
		printf("%d번째 값을 입력하세요 >> ", i + 1);
		scanf_s("%d", &key);
		InsertValue(key);
	}

	printf("검색할 키를 입력하세요 >> ");
	scanf_s("%d", &key);

	if (FindValue(key)) {
		printf("검색되었습니다!\n");
	}
	else {
		printf("검색되지않았습니다!\n");
	}
}