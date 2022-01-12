// Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
// 1) All elements smaller than a come first.
// 2) All elements in range a to b come next.
// 3) All elements greater than b appear in the end.
// The individual elements of three sets can appear in any order. You are required to return the modified array.

void threeWayPartition(vector<int> &array, int a, int b)
{
    vector<int> part1, part2, part3;
    int n = array.size();
    for (int i = 0; i < n; i++)
    {
        if (array[i] < a)
            part1.push_back(array[i]);
        else if (array[i] >= a && array[i] <= b)
            part2.push_back(array[i]);
        else
            part3.push_back(array[i]);
    }

    int n1, n2, n3;
    n1 = part1.size(), n2 = part2.size(), n3 = part3.size();
    array.clear();
    for (int i = 0; i < n1; i++)
        array.push_back(part1[i]);
    for (int j = 0; j < n2; j++)
        array.push_back(part2[j]);
    for (int k = 0; k < n3; k++)
        array.push_back(part3[k]);
}