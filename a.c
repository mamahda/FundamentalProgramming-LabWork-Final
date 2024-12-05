#include <stdio.h>

int main()
{
    int n, k, sum = 0;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n / k; i++)
    {
        sum += ((1 + (i * k)) % n);
    }

    printf("%d\n", sum);
    return 0;
}