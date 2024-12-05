#include <stdio.h>

long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    int shift;
    for (shift = 0; ((a | b) & 1) == 0; shift++)
    {
        a >>= 1;
        b >>= 1;
    }

    while ((a & 1) == 0)
    {
        a >>= 1;
    }

    do
    {
        while ((b & 1) == 0)
        {
            b >>= 1;
        }

        if (a < b)
        {
            long long t = b;
            b = a;
            a = t;
        }

        a = a - b;
    } while (a != 0);

    return b << shift;
}

int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long fpb = gcd(n, k);
    long long x = n + fpb - 1;
    if (x % fpb == 0)
    {
        x = (x / fpb) - 1;
    }
    else
    {
        x = x / fpb;
    }
    long long total = (x * (2 + (x - 1) * fpb)) / 2;

    printf("%lld\n", total);
    return 0;
}