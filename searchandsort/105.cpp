// Given three distinct numbers A, B and C. Find the number with value in middle (Try to do it with minimum comparisons).

int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        if(A>B)
        swap(A,B);
        if(B>C)
        swap(B,C);
        if(A>B)
        swap(A,B);
        return B;
    }