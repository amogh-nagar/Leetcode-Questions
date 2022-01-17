class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<int> freq(mx+1,0),dp(mx+1,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]+=nums[i];
        }
        dp[0]=freq[0];
        dp[1]=freq[1];
        for(int i=2;i<mx+1;i++){
            dp[i]=max(dp[i-2]+freq[i],dp[i-1]);
        }
        
        return dp[mx];
        
    }
};