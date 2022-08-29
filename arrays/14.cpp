// Given an array arr[] denoting heights of N towers and a positive integer K,
//you have to modify the height of each tower either by increasing or decreasing
//them by K only once. After modifying, height should be a non-negative integer.
// Find out what could be the possible minimum difference of the height of shortest
//and longest towers after you have modified each tower.


int getMinDiff(int arr[], int n, int k) {
	sort(arr, arr + n);
	int currMin = arr[0];
	int currMax = arr[n - 1];
	int ans = currMax - currMin;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] - k < 0) continue;
		currMin = min(arr[0] + k, arr[i] - k);
		currMax = max(arr[i - 1] + k, arr[n - 1] - k);
		ans = min(ans, currMax - currMin);
	}
	return ans;
}

//approach
/*
agar [3,6] diya hai to yahi sochege ki 3 increase kare aur 6 decrease kare
maan lo koi array di hai [a,b,c,d] to iska max diff = d-a;
ab hamara main kaam hai(d-a) ko kam krna,jiskar matlab
(a,d)---> ki range ghatana ________a________________d__________
                           --------------a-------d------------- in order to minimize the diff
------a-------b-------c--------------d (d-a)>(c-b);
ham chahte hain ki koi do adjcent element mil jaye ------p-q----- (p+k,q-k) p ko maximum bana de aur q ko min
to p+k ki maximum banane ki help krne ke liye sbhi,q ke baad element ko -k kr denge
similarly q-k ko min banane ke liye p ke pahle sb plus kr denge
max(arr[q-1]+k,arr[last]-k);
min(arr[q]-k,arr[0]+k);

*/