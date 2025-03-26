/*
* 실행 예시
* 11 22 54 64 78 99
*  
* 충돌 발생 시, 이 데이터를 버리지 말고 다른 버킷에 저장하자
* 충돌이 발생하면, 오른쪽 버킷에 저장하고
* 또 그 버킷도 차 있으면 그 오른쪽 버킷에 채워 넣자 -> 버킷 이동
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

	// 슬롯이 비어있는 것을 찾기
	while (hashtable[bucket][0] != 0)
	{
		bucket += 1;
	}
	hashtable[bucket][0] == nKey;
}

int FindValue(int nKey)
{
	int bucket = Hash(nKey);

	while (hashtable[bucket][0] != 0)
	{
		if (hashtable[bucket][0] == nKey) {
			return 1;
		}
		bucket += 1;
	}
}

void main()
{
	int key = 0;
	memset(hashtable, 0, sizeof(hashtable));

	for (int i = 0; i < 4; i++)
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