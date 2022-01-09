// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// Note: can you take care of the duplicates without using any additional Data Structure?

// if all positive

public:
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int max_index;
    max_index = max(A[n1 - 1], B[n2 - 1]);
    max_index = max(max_index, C[n3 - 1]);
    int arr[(max_index) + 1];
    for (int i = 0; i <= max_index; i++)
        arr[i] = 0;
    for (int i = 0; i < n1; i++)
    {
        int index = A[i];
        if (arr[index] == 1)
            continue;
        arr[index]++;
    }

    for (int j = 0; j < n2; j++)
    {
        int index = B[j];
        if (arr[index] == 2)
            continue;
        arr[index]++;
    }

    for (int k = 0; k < n3; k++)
    {
        int index = C[k];
        if (arr[index] == 3)
            continue;
        arr[index]++;
    }

    vector<int> common;
    for (int t = 0; t <= max_index; t++)
        if (arr[t] == 3)
            common.push_back(t);
    return common;
}

// combination of positive and negative

public:
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    set<int> a;
    set<int> b;
    set<int> c;
    set<int>::iterator itr1; // set<int, greater<int> >::iterator itr;
    set<int>::iterator itr2;
    set<int>::iterator itr3;
    for (int i = 0; i < n1; i++)
        a.insert(A[i]);
    for (int j = 0; j < n2; j++)
        b.insert(B[j]);
    for (int k = 0; k < n3; k++)
        c.insert(C[k]);
    vector<int> abc;
    vector<int> common;
    int size1 = a.size();
    int size2 = b.size();
    int size3 = c.size(); // itr != s2.end()
    for (itr1 = a.begin(); itr1 != a.end(); itr1++)
        abc.push_back(*itr1);
    for (itr2 = b.begin(); itr2 != b.end(); itr2++)
        abc.push_back(*itr2);
    for (itr3 = c.begin(); itr3 != c.end(); itr3++)
        abc.push_back(*itr3);
    // logic abc ready
    int size = size1 + size2 + size3;
    sort(abc.begin(), abc.end());
    for (int i = 0; i < (size - 2);)
    {
        if (abc[i] == abc[i + 1] && abc[i + 1] == abc[i + 2])
        {
            common.push_back(abc[i]);
            i += 3;
        }
        else
            i++;
    }
    return common;
}

// simple solution

while (x < array1.length && y < array2.length && z < array3.length)
{
    if (array1[x] == array2[y] && array2[y] == array3[z])
    {
        common.add(array1[x]);
        x++;
        y++;
        z++;
    }
    else if (array1[x] < array2[y])
    {
        x++;
    }
    else if (array2[y] < array3[z])
    {
        y++;
    }
    else
    {
        z++;
    }
}