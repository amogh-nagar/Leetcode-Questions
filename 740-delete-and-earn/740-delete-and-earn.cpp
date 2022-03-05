class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<int> freq(mx+1,0),dp(mx+1,0);
        for(int i=0;i<n;i++){
            freq[nums[i]]+=nums[i];
        }
        dp[1]=freq[1];
        for(int i=2;i<=mx;i++){
            dp[i]=max(freq[i]+dp[i-2],dp[i-1]);
        }
        return dp[mx];    
    }
};