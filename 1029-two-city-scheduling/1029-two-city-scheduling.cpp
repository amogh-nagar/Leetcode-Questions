class Solution {
public:
    int dp[101][101][101];
    int solve(vector<vector<int>>& c){
        int n=c.size();
        dp[0][0][1]=c[0][1];
        dp[0][1][0]=c[0][0];
        for(int i=1;i<n;i++){
            dp[i][0][i+1]=dp[i-1][0][i]+c[i][1];
            dp[i][i+1][0]=dp[i-1][i][0]+c[i][0];
            for(int j=1,k=i;j<=i&&k>0;j++,k--){
                dp[i][j][k]=min(dp[i-1][j][k-1]+c[i][1],dp[i-1][j-1][k]+c[i][0]);   
                
            }
        }
        return dp[n-1][n/2][n/2];
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        
        memset(dp,0,sizeof(dp));
        
        return solve(costs);
    }
};