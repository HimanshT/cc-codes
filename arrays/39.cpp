// Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.
int PalinArray(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int copy = a[i];
        vector<int> reverse;
        while (copy != 0)
        {
            reverse.push_back(copy % 10);
            copy = copy / 10;
        }
        int number = 0;
        int j = 0;
        int n2 = reverse.size();
        while (j < n2)
        {
            number += reverse[j] * pow(10, n2 - j - 1);
            j++;
        }
        if (number != a[i])
            return 0;
    }
    return 1;
}

// simple method

int reverseTheNumber(int n)
{
    int ans = 0;
    while (n)
    {
        int rem = n % 10;
        n = n / 10;
        ans = ans * 10 + rem;
    }
    return ans;
}