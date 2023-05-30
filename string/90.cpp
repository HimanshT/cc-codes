// Given a string S with repeated characters.
// The task is to rearrange characters in a string such that no two adjacent characters are the same.

//base condition
if (str.length() == 1) return "1";
unordered_map<char, int> umap;
for (char c : str)
	umap[c]++;
//if the string only contains one type of characters
if (umap.size() == 1) return "0";
//filling in priority queue
priority_queue<int> pq;
for (auto &x : umap) pq.push(x.second);
int x1 = pq.top(); pq.pop();
int x2 = pq.top(); pq.pop();
string ans = "x";
while (1)
{
	if (x1 > x2)
	{
		x1 -= x2;
		if (pq.empty() and x1 == 1)
		{
			ans = "1";
			break;
		} else if (pq.empty() and x1 != 1) return "1";
		else {
			x2 = pq.top(); pq.pop();
		}
	} else if (x2 > x1) {
		x2 -= x1;
		if (pq.empty() and x2 == 1) return "1";
		else if (pq.empty() and x2 != 1) return "1";
		else {
			x1 = pq.top(); pq.pop();
		}
	} else {
		if (pq.empty()) return "1";
		x1 = 0, x2 = 0;
		x1 = pq.top(); pq.pop();
		if (!pq.empty())
		{
			x2 = pq.top(); pq.pop();
		}
	}
}
return ans;