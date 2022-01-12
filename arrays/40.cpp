// Given an array arr[] of N integers, calculate the median

int find_median(vector<int> v)
{
    int n = v.size();
    sort(v.begin(), v.end());
    int median;
    if (n % 2 == 0)
    {
        int index = n / 2;
        median = (v[index] + v[index - 1]) / 2;
        return median;
    }
    else
    {
        int index = n / 2;
        return (v[index]);
    }
}