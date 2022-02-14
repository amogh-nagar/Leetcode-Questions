class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(auto x:stones){
            sum+=x;
        }
        int n=stones.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,0));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0){
                    dp[i][j]=0;
                }
                if(j==0){
                    dp[i][j]=1;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=stones[i-1]){
                dp[i][j]=dp[i][j] || dp[i-1][j-stones[i-1]];
                    
                }
            }
        }
        int mind=INT_MAX;
        for(int j=0;j<=sum;j++){
            if(dp[n][j]){
                mind=min(mind,abs(sum-2*j));
            }
        }
        return mind;
    }
};