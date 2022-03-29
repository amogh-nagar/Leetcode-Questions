class Solution {
    int dp[5001];
public:
    int solve(vector<int> &prices, int n, int ind){
        int maxi=prices[n-1];
        dp[n-1]=0;
        for (int i=n-2;i>=0;i--){
            maxi=max(maxi,prices[i]+(i+2<n ? dp[i+2] : 0));
            dp[i]=max(dp[i+1],maxi-prices[i]);
        }
        return dp[0];
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,n,0);
    }
};