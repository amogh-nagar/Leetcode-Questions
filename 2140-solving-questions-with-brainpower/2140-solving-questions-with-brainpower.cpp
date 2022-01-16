class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long int> dp(n,0);
        long long int m=questions[n-1][0];
        dp[n-1]=questions[n-1][0];
        for(int i=n-2;i>=0;i--){
            int x=questions[i][1];
            // int nm=INT_MIN;
            // for(int j=i+1;j<=i+x && j<n;j++){
            //     nm=max(nm,dp[j]);
            // }
            // cout<<nm<<endl;
            dp[i]=max(dp[i+1],questions[i][0]+(i+x+1<n?dp[i+x+1]:0));
            // cout<<dp[i]<<endl;
            m=max(m,dp[i]);
        }
        return m;
    }
};