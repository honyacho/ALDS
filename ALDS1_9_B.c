#include <stdio.h>
int arr[500001];

void maxHeapify(int* xs, int idx, int size)
{
	int left = idx*2, right = idx*2+1, largest = 0;
	if (left <= size && arr[idx] < arr[left]) {
		largest = left;
	} else {
		largest = idx;
	}
	if (right <= size && arr[right] > arr[largest]) {
		largest = right;
	}

	if (largest != idx) {
		int tmp = arr[idx];
		arr[idx] = arr[largest];
		arr[largest] = tmp;
		maxHeapify(xs, largest, size);
	}
}

int main()
{
	int size = 0;
	scanf("%d", &size);
	for (int i = 1; i <= size; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = size / 2; i >= 1; i--) {
		maxHeapify(arr, i, size);
	}
	for (int i = 1; i <= size; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
}
