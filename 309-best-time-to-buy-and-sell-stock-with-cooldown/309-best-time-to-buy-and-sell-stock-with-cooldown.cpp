class Solution {
    int dp[5001];
public:
    int solve(vector<int> &prices, int n, int ind){
        if (ind>=n) return 0;
        if (dp[ind]!=-1) return dp[ind];
        int max_val=0;
        for (int i=ind+1;i<n;i++){
            if (prices[ind]<prices[i]){
                max_val=max(max_val, prices[i]-prices[ind]+solve(prices,n,i+2));
            }
        }
        max_val=max(max_val,solve(prices,n,ind+1));
        return dp[ind]=max_val;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,n,0);
    }
};