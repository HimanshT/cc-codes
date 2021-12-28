// Write a program to reverse an array or string
#include <stdio.h>
typedef long long ll;
int main()
{
    ll arr[10];
    for (int i = 0; i < 10; i++)
        scanf("%lld", &arr[i]);
    ll arr1[10];
    for (int i = 0; i < 10; ++i)
    {
        arr1[i] = arr[9 - i];
        printf("%lld ", arr1[i]);
    }
    return 0;
}

// the other way of solving is iterating it from back and front side :. Imp: while(start<end)