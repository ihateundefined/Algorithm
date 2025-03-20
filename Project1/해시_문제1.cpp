/*
* 0보다 큰 정수값을 사용자로부터 입력 받아서 해시테이블에 저장한다.
* 단, 해시테이블 생성 시 버킷 수는 10개 슬롯 수는 1개로 지정한다.
* 해시테이블에서 값이 0이면 빈 데이터 공간을 의미한다.
* 
* 5개의 각 정수를 입력 시 각각의 입력값은 입력할 버킷을 찾는 해시 함수에 의해 버킷을 찾아 해시테이블에 저장한다.
* 5개의 정수 입력이 끝났으면, 검색할 키를 입력 받아 검색 결과를 출력
* 검색 시에도 해시함수를 이용하여 해시테이블을 검색한다.
* 
* 각 기능은 함수로 모듈화 하여 구현한다.
* 
* 해시함수 이름은 Hash
* 값 입력 함수 이름은 InsertValue
* 값 검색 함수 이름은 FindValue
* 
* 입력
* 입력할 키값을 프로그램 콘솔 키보드로부터 입력 받는다.
* 키값은 양의 정수로만 입력 받는다.
* 입력값 : 11, 22, 54, 396, 87
* 
* 출력
* 입력한 키값에 따른 검색 결과를 프로그램 콘솔 터미널에 출력한다.
* 사용자가 입력한 키값이 검색되었을 경우 : “검색되었습니다.”
* 사용자가 입력한 키값이 검색되지 않았을 경우 : “검색되지 않았습니다.”
* 
* 실행 예시
* 키를 5개 입력하세요.
* 11 22 54 396 87
* 검색할 키를 입력하세요.
* 22
* 검색되었습니다.
*/

#include <stdio.h>
#include <string.h>

// define 치환하겠다 ... 매크로 정의
#define BK 10
#define SL 1

int hashtable[BK][SL];

int Hash(int nKey) {
    return nKey % 10;
}

void InsertValue(int nKey)
{
	int bucket = Hash(nKey);

	// 메모리를 0으로 초기화했으니, 값이 0일때는 nKey로 대체하고
	// 만일 다른 값이 이미 들어있는 경우에는
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
	memset(hashtable, 0, sizeof(hashtable)); // 메모리 초기화 함수

	for (int i = 0; i < 5; i++)
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