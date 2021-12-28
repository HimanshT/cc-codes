// Maximum and minimum of an array using minimum number of comparisons
#include <stdio.h>
typedef long long ll;

struct pair
{
    int max;
    int min;
};

// log(n)-time complexity
struct pair minmax(int arr[], int n)
{
    struct pair findValue;
    findValue.max = findValue.min = arr[0];
    if (n == 0)
        return findValue;
    else
    {
        for (int i = 1; i < n; ++i)
        {
            if (arr[i] > findValue.max)
                findValue.max = arr[i];
            if (arr[i] < findValue.min)
                findValue.min = arr[i];
        }
    }
    return findValue;
}

int main()
{
    int arr[] = {1, 7, 5, 3, 8};
    int n = sizeof(arr) / sizeof(int);
    struct pair first = minmax(arr, n);
    printf("The max and min are %d and %d\n", first.max, first.min);
    return 0;
}