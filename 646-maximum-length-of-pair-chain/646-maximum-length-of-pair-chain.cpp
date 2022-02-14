class Solution {
public:
    bool static comp(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        int n=pairs.size();
        vector<int> dp(n,0);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int x=0;
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    x=max(x,dp[j]);
                }
                
            }
            dp[i]=x+1;
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};