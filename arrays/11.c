#include <stdio.h>
void findUnion(int a[], int n, int b[], int m)
{
    int arr[n + m];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        arr[index] = a[i];
        index++;
    }
    for (int j = 0; j < m; j++)
    {
        arr[index] = b[j];
        index++;
    }
    int count = 1;
    for (int k = 1; k < (n + m); k++)
    {
        int find = 0;
        for (int i = 0; i < k; i++)
        {
            if (arr[i] == arr[k])
            {
                find = 1;
                break;
            }
        }
        if (find == 0)
            count++;
    }
    printf("%d\n", count);
}
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    findUnion(a, 5, b, 8);
    return 0;
}

// can be solved using set ds,map-->basic logic is that they do not store repeated value
// sorting and searching can be used