class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(auto x:edges){
            dp[x[0]][x[1]]=dp[x[1]][x[0]]=x[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j){
                        continue;
                    }
                    if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX && dp[i][j]>dp[i][k]+dp[k][j]){
                        dp[i][j]=dp[i][k]+dp[k][j];
                    }
                }
            }
        }
        
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int k=0;
            for(int j=0;j<n;j++){
                if(dp[i][j]<=distanceThreshold){
                    k++;
                }
            }
            mini=min(mini,k);
        }
        int x=0;
        for(int i=0;i<n;i++){
            int k=0;
            for(int j=0;j<n;j++){
                if(dp[i][j]<=distanceThreshold){
                    k++;
                }
            }
            if(k==mini){
                x=i;
            }
        }
        return x;
        
    }
};