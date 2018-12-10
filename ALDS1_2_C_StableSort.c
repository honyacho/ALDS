#include <stdio.h>
#include <string.h>
int dict[128][128];
int sort_bub[36][2];
int sort_sel[36][2];

void selection_sort(int arr[][2], int len)
{
	int tmp[2];
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i+1; j < len; j++)
		{
			if (arr[min][1] > arr[j][1])
			{
				min = j;
			}
		}
		if (i != min) {
			tmp[0] = arr[i][0];
			tmp[1] = arr[i][1];
			arr[i][0] = arr[min][0];
			arr[i][1] = arr[min][1];
			arr[min][0] = tmp[0];
			arr[min][1] = tmp[1];
		}
	}
}

void bubble_sort(int arr[][2], int len)
{
	int tmp[2];
	for (int i = 0; i < len; i++)
	{
		int max = len - i;
		for (int j = 1; j < max; j++)
		{
			if (arr[j - 1][1] > arr[j][1])
			{
				tmp[0] = arr[j-1][0];
				tmp[1] = arr[j-1][1];
				arr[j-1][0] = arr[j][0];
				arr[j-1][1] = arr[j][1];
				arr[j][0] = tmp[0];
				arr[j][1] = tmp[1];
			}
		}
	}
}

int main()
{
	int len, tmp;
	char mark;
	char stable_bub[256] = "Stable", stable_sel[256] = "Stable";

	scanf("%d\n", &len);

	scanf("%c", &mark);
	scanf("%d", &tmp);
	sort_bub[0][0] = mark;
	sort_bub[0][1] = tmp;
	sort_sel[0][0] = mark;
	sort_sel[0][1] = tmp;
	dict[mark][tmp] = 0;

	for (int i = 1; i < len; i++) {
		scanf(" %c", &mark);
		scanf("%d", &tmp);
		sort_bub[i][0] = mark;
		sort_bub[i][1] = tmp;
		sort_sel[i][0] = mark;
		sort_sel[i][1] = tmp;
		dict[mark][tmp] = i;
	}

	bubble_sort(sort_bub, len);
	selection_sort(sort_sel, len);

	printf("%c%d", (char)sort_bub[0][0], sort_bub[0][1]);
	for (int i = 1; i < len; i++) {
		printf(" %c%d", (char)sort_bub[i][0], sort_bub[i][1]);

		if (sort_bub[i-1][1] == sort_bub[i][1] && dict[sort_bub[i-1][0]][sort_bub[i-1][1]] > dict[sort_bub[i][0]][sort_bub[i][1]]) {
			strcpy(stable_bub, "Not stable");
		}
	}
	printf("\n%s\n", stable_bub);

	printf("%c%d", (char)sort_sel[0][0], sort_sel[0][1]);
	for (int i = 1; i < len; i++) {
		printf(" %c%d", (char)sort_sel[i][0], sort_sel[i][1]);

		if (sort_sel[i-1][1] == sort_sel[i][1] && dict[sort_sel[i-1][0]][sort_sel[i-1][1]] > dict[sort_sel[i][0]][sort_sel[i][1]]) {
			strcpy(stable_sel, "Not stable");
		}
	}
	printf("\n%s\n", stable_sel);

	return 0;
}
