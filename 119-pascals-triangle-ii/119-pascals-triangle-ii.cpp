class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> dp(n+1);
        vector<int> v;
        for(int i=0;i<=n;i++){
            dp[i]=vector<int>(i+1,1);
            for(int j=1;j<i;j++){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
        v=dp.back();
        return v;
    }
};