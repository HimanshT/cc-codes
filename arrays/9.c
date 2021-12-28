// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

void sort012(int a[], int n)
{

    int b[n];
    int index = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] == 0)
        {
            b[index] = 0;
            index++;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (a[j] == 1)
        {
            b[index] = 1;
            index++;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (a[j] == 2)
        {
            b[index] = 2;
            index++;
        }
    }
    for (int k = 0; k < n; k++)
    {
        a[k] = b[k];
    }
}