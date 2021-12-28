// Move all negative numbers to beginning and positive to end with constant extra space

#include <stdio.h>

void shift(int arr[], int n)
{
    int neg = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] < 0)
            neg++;
    }

    int k = neg;
    printf(" The total neg nos are%d\n", neg);

    for (int j = 0; j < neg; j++)
    {
        if (arr[j] > 0)
        {
            for (; k < n; k++)
            {
                if (arr[k] < 0)
                {
                    int swap;
                    swap = arr[k];
                    arr[k] = arr[j];
                    arr[j] = swap;
                    break;
                }
            }
        }
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the no. of elements in the array");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    shift(arr, n);
    print(arr, n);
    return 0;
}

// gfg code
//  void rearrange(int arr[], int n)
//  {
//      int j = 0;
//      for (int i = 0; i < n; i++)
//      {
//          if (arr[i] < 0)
//          {
//              if (i != j)
//                  swap(arr[i], arr[j]);
//              j++;
//          }
//      }
//  }