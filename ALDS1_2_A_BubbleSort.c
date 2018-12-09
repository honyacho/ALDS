#include <stdio.h>
int arr[100];

int main()
{
	int len, tmp, cnt = 0;
	scanf("%d", &len);

	for (int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < len; i++)
	{
		int max = len - i;
		for (int j = 1; j < max; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
				cnt++;
			}
		}
	}

	printf("%d", arr[0]);
	for (int i = 1; i < len; i++)
	{
		printf(" %d", arr[i]);
	}
	printf("\n");
	printf("%d\n", cnt);
}
