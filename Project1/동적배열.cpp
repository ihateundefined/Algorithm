#include <stdio.h>
#include <memory>

int* ar;
int size;
int num;
int growby;

void InitArray(int asize, int agrowby) {
	size = asize;
	growby = agrowby;
	num = 0;
	ar = (int*)malloc(size * sizeof(int));
}

void Insert(int idx, int value) {
	int need = num + 1;
	if (need > size) {
		size = need + growby;

		// malloc으로 할당받은 메모리를 기준으로 가져오기..?
		ar = (int*)realloc(ar, size * sizeof(int));
	}

	memmove(ar + idx + 1, ar + idx, (num - idx) * sizeof(int));
	ar[idx] = value;
	num++;
}

void DumpArray() {
	for (int i = 0; i < num; i++) {
		printf("%2d ", ar[i]);
	}
	printf("\n");
}

void main()
{
	InitArray(10, 5);
	for (int i = 1; i <= 8; i++) {
		Insert(num, i);
	}

	Insert(3, 10);
	DumpArray();
	Insert(3, 11);
	DumpArray();
}