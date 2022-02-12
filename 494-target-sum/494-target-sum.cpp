class Solution {
public:
    map<pair<int,int>,int> dp;
    int solve(vector<int> nums,int idx,int target){
        
        if(idx==0){
            if(target==0 && nums[idx]==0){
              return 2;
            }
            if(target==0 || target==nums[0]){
              return 1;
            }
            return 0;
        }
        if(dp.find({idx,target})!=dp.end()){
            return dp[{idx,target}];
        }
        int np=solve(nums,idx-1,target);
        int p=0;
        if(nums[idx]<=target)
        p=solve(nums,idx-1,target-nums[idx]);
        
        return dp[{idx,target}]=np+p;
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto x:nums)
            sum+=x;
        
        int r=(sum-target)/2;
        if((sum-target)%2!=0){
            return 0;
        }
        return solve(nums,nums.size()-1,r);
        
    }
};