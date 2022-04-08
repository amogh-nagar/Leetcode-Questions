class Solution {
public:
    
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(1001,vector<int>(1001,0));
        int maxi=0;
        dp[0][0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int x=nums[j]-nums[i]+500;
                dp[i][x]=max(2,dp[j][x]+1);
                maxi=max(maxi,dp[i][x]);
            }
        }
        return maxi;
    }
};