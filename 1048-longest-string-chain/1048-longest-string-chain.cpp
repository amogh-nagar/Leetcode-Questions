class Solution
{
public:
    static bool comp(string &a, string &b) {
        return a.size() < b.size();
    }
    bool solve(string x, string y)
    {
        if (x.length() != y.length() + 1)
        {
            return false;
        }
        int l = 0, m = 0;
        while (l < x.length() && m < y.length())
        {
            if(l-m>1){
                return false;
            }
            if (x[l] != y[m])
            {
                
                l++;
            }
            else
            {
                l++;
                m++;
            }
        }
        return m==y.length();
    }

    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        int m = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (solve(words[i], words[j]))
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                m=max(m,dp[i]);
                } }
        }
        return m;
    }
};