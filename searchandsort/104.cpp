// Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. You are given a number N, you have to output the number of integers less than N in the sample space S.

class Solution {
public:
       int countSquares(int N) {
              // code here
              int x = sqrt(N);
              if (x * x == N) return x - 1;
              return x;
       }
};