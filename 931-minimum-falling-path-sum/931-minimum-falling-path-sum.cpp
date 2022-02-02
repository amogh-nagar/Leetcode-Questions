class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                if(j==0){
                    dp[i][j]=min(dp[i+1][j],dp[i+1][j+1]);
                }
                else if(j==m-1){
                    dp[i][j]=min(dp[i+1][j-1],dp[i+1][j]);
                }else{
                    dp[i][j]=min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]));
                }
                dp[i][j]+=matrix[i][j];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        int mini=INT_MAX;
        for(int j=0;j<m;j++){
            mini=min(mini,dp[0][j]);
        }
        return mini;
    }
};