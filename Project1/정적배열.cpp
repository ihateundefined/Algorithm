#include <stdio.h>
#include <memory>

char ar[16] = "abcdef";

void Insert(int idx, char ch)
{
	// abctdef
	memmove(ar + idx + 1, ar + idx, strlen(ar) - idx + 1);
	ar[idx] = ch;
}

void Delete(int idx)
{
	memmove(ar + idx, ar + idx + 1, strlen(ar) - idx);
}

void main()
{
	printf("���� : %s\n", ar);
	Insert(3, 't');
	printf("���� �� : %s\n", ar);
	Delete(3);
	printf("���� �� : %s\n", ar);
}