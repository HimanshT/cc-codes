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
            if (carry > 0)
            {
                while (carry > 0)
                {
                    facts.insert(facts.begin(), (carry % 10));
                    carry /= 10;
                }
            }
        }
        return facts;
    }
};