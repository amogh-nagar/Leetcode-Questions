class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i]=arr[i-1];
            int val=0;
            for(int j=1;j<=k && j<=i;j++){
                val=max(val,arr[i-j]);
                dp[i]=max(dp[i],val*j+dp[i-j]);
            }
        }
        return dp[n];
    }
};