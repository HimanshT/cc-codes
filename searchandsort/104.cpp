// Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. You are given a number N, you have to output the number of integers less than N in the sample space S.

 int countSquares(int N) {
        // code here
    double value1=sqrt(N);
    double value2=floor(value1);
    if(value1-value2>0)
    return int(value2);
    else
    return int(value2-1);
       
        
    }