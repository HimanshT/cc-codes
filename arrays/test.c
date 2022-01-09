#include <stdio.h>
#include <string.h>
#include <math.h>

long long mod(int x, int y, int m)
{
    if (y == 0)
        return 1;
    if (y % 2 == 0)
        return (mod(x, y / 2, m) * mod(x, y / 2, m)) % m;
    return ((x % m) * (mod(x, y - 1, m))) % m;
}

int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        char str[100001];
        scanf("%s", str);
        long long int m = pow(10, 9) + 1;
        int len = strlen(str);
        long long arr[len];
        // logic
        for (int i = 0; i < len; i++)
        {
            long long pw = len - i - 1;
            long long first = mod(26, pw, m);
            arr[i] = first * ((str[i] - 64) % m);
            arr[i] = arr[i] % m;
        }
        long long sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += arr[i];
        }
        printf("%lld\n", sum % m);
    }
    return 0;
}