#include <stdio.h>

int main()
{
	int m, n, tmp;
	scanf("%d %d", &m, &n);
	if (m < n)
	{
		tmp = m;
		m = n;
		n = tmp;
	}
	for (;;)
	{
		tmp = m % n;
		m = n;
		n = tmp;
		if (n == 0) break;
	}
	printf("%d\n", m);
	return 0;
}
