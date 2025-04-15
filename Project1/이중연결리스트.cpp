#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Node
{
	int val; // data
	Node* pNext; // link
};

// ���� ���� ����Ʈ
struct DoubleNode
{
	int val; // data
	Node* pPrev; // ���� ��� link
	Node* pNext; // link
};

Node* head;

Node* InsertNode(Node* Target, Node* aNode)
{
	Node* New;
	New = (Node*)malloc(sizeof(Node));
	// val : 1, pNext : �����Ⱚ
	*New = *aNode;
	New->pNext = Target->pNext;
	Target->pNext = New;
	return New;
}

bool DeleteNode(Node* Target)
{
	Node* Del;
	Del = Target->pNext;

	// ������ ����̸� ���� �ʿ� ����
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
	// malloc�� void pointer�� return�ϹǷ� type casting �ݵ�� �ʿ�
	// head ����
	head = (Node*)malloc(sizeof(Node));
	head->pNext = NULL;

	// node �߰�
	Node* Now, Temp;
	Now = head;
	for (int i = 1; i <= 5; i++)
	{
		Temp.val = i;
		Now = InsertNode(Now, &Temp);
	}

	// ����
	DeleteNode(head->pNext);

	// ���
	for (Now = head->pNext; Now; Now = Now->pNext)
	{
		printf("%d\t", Now->val);
	}

	// �޸� ����
	while (DeleteNode(head)) {}

	free(head);
	head = NULL;
}