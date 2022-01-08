class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int>(5,0));
        for(int i=0;i<5;i++){
            dp[1][i]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<5;j++){
                for(int k=j;k<5;k++){
                    dp[i][j]+=dp[i-1][k];
                }
            }
        }
        int x=0;
        for(int i=0;i<5;i++){
            x+=dp[n][i];
        }
        return x;
    }
};