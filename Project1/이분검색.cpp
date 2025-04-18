/*
* 이분 검색
* [합격자 조회]라는 메뉴 -> 수험자가 수험번호를 입력하면 합격 여부를 알 수 있게 시스템의 기능을 추가하려고 한다.
* [합격자 조회] 기능 수행 시 동작하는 검색 알고리즘을 작성하라.
* (단, 모든 데이터는 오름차순으로 정렬되어 있다.)
* 
* 예를 들어 19개의 정수들이 배열 형태로 크기순으로 잘 나열되어 있다고 하자.
* 이 배열에서 키를 찾는데, 29라는 키 값을 찾는다고 하면 다음과 같은 번호 순서대로 검색을 해야 한다.

          [그림 첨부]

           Lower
:  검색해야 할 데이터 범위의 최소값

           Upper
: 검색해야 할 데이터 범위의 최대값

           Middle
: 검색해야 할 데이터 범위의 중간값



입력

입력할 키값을 프로그램 콘솔 키보드로부터 입력 받는다.

입력 키값은 정수로만 입력 받는다.

검색 대상 데이터는 배열 형태로 코드 상에 오름차순으로 작성한다.

int arr[]={2,6,13,19,21,21,23,29,35,48,62,89,90,95,99,102,109,208,629};


출력


입력한 키값에 따른 검색 결과를 프로그램 콘솔 터미널에 출력한다.

사용자가 입력한 수험번호가 검색되었을 경우 : “축하합니다. 합격하셨습니다.”

사용자가 입력한 수험번호가 검색되지 않았을 경우 : “아쉽지만, 불합격하셨습니다.”


실행예시


[합격자 조회]

TestCase는 다음과 같다.
입력값 : 29

수험번호를 입력하세요 : 29
축하합니다. 합격하셨습니다.
*/

#include <stdio.h>

void main()
{
    int arr[] = { 2,6,13,19,21,21,23,29,35,48,62,89,90,95,99,102,109,208,629 };
    // arr[] 배열의 크기 구하기
    unsigned int size = sizeof(arr)/sizeof(arr[0]);
    // 찾으려고 하는 값
    int key = 629;

    // 2의 index == 0
    unsigned int lower = 0;
    // 629 index 구하기
    unsigned int upper = size - 1;
    // 일단 mid를 0으로 초기화
    unsigned int mid = 0;

    // 무한 루프
    // for (;;)
    while (true)
    {
        // 중간 위치 index 구하기
        mid = (lower + upper) / 2;

        if (arr[mid] == key) {
            printf("%d번째에 있습니다.\n", mid + 1 );
            return;
        }

        if (arr[mid] > key) {
            upper = mid - 1;
        }
        else {
            lower = mid + 1;
        }

        if (upper < lower) {
            printf("해당 값을 찾을 수 없습니다.\n");
            return;
        }
    }
}