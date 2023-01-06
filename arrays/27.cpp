// Given an integer N, find its factorial.
class Solution
{
public:
    vector<int> factorial(int N)
    {
        vector<int> facts;
        int value = 1;
        facts.push_back(value);
        for (int i = 2; i <= N; i++)
        {
            int size = facts.size();
            int carry = 0;
            for (int j = size - 1; j >= 0; j--)
            {
                int product = facts[j] * i + carry;
                if (product > 9)
                    carry = product / 10;
                else
                    carry = 0;
                facts[j] = product % 10;
            }

            while (carry > 0)
            {
                facts.insert(facts.begin(), (carry % 10));
                carry /= 10;
            }

        }
        return facts;
    }
};

//Another solution based on queue
class Solution {
public:
    vector<int> factorial(int N) {
        queue<int> q;
        q.push(N);
        for (int i = N - 1; i > 1; i--)
        {
            int n = q.size();
            int carry = 0;
            while (n > 0)
            {
                n--;
                int currval = i * q.front();
                q.pop();
                q.push((currval + carry) % 10);
                carry = (currval + carry) / 10;
            }
            while (carry > 0)
            {
                q.push(carry % 10);
                carry /= 10;
            }
        }
        int n = q.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] = q.front(); q.pop();
        }
        return ans;
    }
};