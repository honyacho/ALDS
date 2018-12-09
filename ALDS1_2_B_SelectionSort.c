#include <stdio.h>

int arr[100];

int main() {
	int len, tmp, swp_cnt = 0;
	scanf("%d", &len);
	for (int i = 0; i < len; i++) scanf("%d", &arr[i]);

	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i+1; j < len; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (i != min) {
			tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
			swp_cnt++;
		}
	}

	printf("%d", arr[0]);
	for (int i = 1; i < len; i++)
	{
		printf(" %d", arr[i]);
	}
	printf("\n%d\n", swp_cnt);
}
