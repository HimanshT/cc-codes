// Given an array, rotate the array by one position in clock-wise direction.

void rotate(int arr[], int n)
{
    int temp = arr[0];
    int idx = 0;
    int count = 0;
    while (count <= n)
    {
        int newIdx = (idx + 1 % n + n) % n;
        swap(arr[newIdx], temp);
        idx = newIdx;
        count++;
    }
}

//universal formula for rotation

//if array you are supposed to find new index
//new idx = (idx-0+x%len+len)%len+0;
//for char array=(str[i]-'a'+inc%len+len)