#include <stdio.h>
#include <math.h>
int primes[10001];
int buf2[10001];

int main()
{
	int len, res, len_primes, len_buf2;
	scanf("%d", &len);
	primes[0] = 2;
	buf2[0] = 0;
	len_primes = 1;
	len_buf2 = 0;
	res = 0;

	for (int k = 2; k <= 10000; k++)
	{
		int is_prime = 2;
		for (int j = 0; (j < len_primes) && is_prime; j++)
		{
			is_prime = k % primes[j];
		}
		if (is_prime) {
			primes[len_primes] = k;
			len_primes++;
		}
	}


	for (int i = 0; i < len; i++)
	{
		int p = 0, already = 0;
		scanf("%d", &p);

		for (int j = 0; j < len_buf2 && !already; j++) {
			if (buf2[j] == p) {
				already = 1;
			}
		}

		if (!already) {
			int maxp = (int)sqrt((double)p) + 1;
			int is_prime = 1;
			for (int k = 0; (primes[k] < maxp) && k < len_primes && is_prime; k++) {
				is_prime = p % primes[k];
			}
			if (is_prime) {
				buf2[len_buf2] = p;
				len_buf2++;
				res++;
			}
		}
	}

	// for (int i = 0; i < len_buf2; i++) printf("nakami: %d\n", buf2[i]);

	printf("%d\n", res);
	return 0;
}
