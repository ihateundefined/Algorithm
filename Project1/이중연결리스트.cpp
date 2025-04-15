#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Node
{
	int val; // data
	Node* pNext; // link
};

// 이중 연결 리스트
struct DoubleNode
{
	int val; // data
	Node* pPrev; // 이전 노드 link
	Node* pNext; // link
};

Node* head;

Node* InsertNode(Node* Target, Node* aNode)
{
	Node* New;
	New = (Node*)malloc(sizeof(Node));
	// val : 1, pNext : 쓰레기값
	*New = *aNode;
	New->pNext = Target->pNext;
	Target->pNext = New;
	return New;
}

bool DeleteNode(Node* Target)
{
	Node* Del;
	Del = Target->pNext;

	// 마지막 노드이면 지울 필요 없음
	if (Del == NULL)
	{
		return false;
	}

	Target->pNext = Del->pNext;
	free(Del);

	return true;
}

void main()
{
	// malloc는 void pointer를 return하므로 type casting 반드시 필요
	// head 생성
	head = (Node*)malloc(sizeof(Node));
	head->pNext = NULL;

	// node 추가
	Node* Now, Temp;
	Now = head;
	for (int i = 1; i <= 5; i++)
	{
		Temp.val = i;
		Now = InsertNode(Now, &Temp);
	}

	// 삭제
	DeleteNode(head->pNext);

	// 출력
	for (Now = head->pNext; Now; Now = Now->pNext)
	{
		printf("%d\t", Now->val);
	}

	// 메모리 해제
	while (DeleteNode(head)) {}

	free(head);
	head = NULL;
}