#include <stdio.h>
int arr[1000000000];
int seed[100];
int cnt = 0;

void insertion_sort(int* arr, int len, int g)
{
	for (int i = g; i < len; i++)
	{
		int tmp = arr[i], j = i - g;
		while (j >= 0 && arr[j] > tmp)
		{
			arr[j+g] = arr[j];
			j = j - g;
			cnt++;
		}
		arr[j+g] = tmp;
	}
}

int main()
{
	int len;
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}

	int power = 1, seed_count = 0;
	while (power <= len)
	{
		seed[seed_count++] = power;
		// printf("%d\n", seed[seed_count-1]);
		power = 2*power;
	}
	printf("%d\n", seed_count);

	for (int i = 0; i < seed_count; i++)
	{
		printf("%d ", seed[seed_count-i-1]);
		insertion_sort(arr, len, seed[seed_count-i-1]);
	}
	printf("\n");
	printf("%d\n", cnt);


	for (int i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}
