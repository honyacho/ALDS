#include <stdio.h>

long heap[1000];

int main()
{
	int i = 0, len = 0;
	scanf("%d", &len);
	for (i = 1; i <= len; i++) {
		scanf("%ld", &heap[i]);
	}
	for (i = 1; i <= len; i++) {
		printf("node %d: key = %ld, ", i, heap[i]);
		if (i / 2 > 0)  {
			printf("parent key = %ld, ", heap[i/2]);
		}
		if (i*2 <= len) {
			printf("left key = %ld, ", heap[i*2]);
		}
		if ((i*2+1) <= len) {
			printf("right key = %ld, ", heap[i*2+1]);
		}
		printf("\n");
	}
	return 0;
}
