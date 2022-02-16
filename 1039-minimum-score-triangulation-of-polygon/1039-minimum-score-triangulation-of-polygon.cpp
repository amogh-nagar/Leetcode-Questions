class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
          
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;j++,i++){
                if(g==0 || g==1){
                    dp[i][j]=0;
                }else if(g==2){
                    dp[i][j]=values[i]*values[i+1]*values[j];
                }else{
                    int mini=INT_MAX;
                    for(int k=i+1;k<=j-1;k++){
                        int t=values[i]*values[k]*values[j];
                        int left=dp[i][k];
                        int right=dp[k][j];
                        mini=min(mini,t+left+right);
                    }
                    dp[i][j]=mini;
                }
            }
        }
        return dp[0][n-1];
    }
};