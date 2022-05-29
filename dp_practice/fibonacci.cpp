// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,


int fib(int n) {
    int prev = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev1;
        prev = prev1;
        prev1 = curr;
    }
    if (n == 0)
        return 0;
    return prev1;
}

