class Solution {
public:
    int dp[17][1<<17];
    // memset(dp,0,sizeof(dp));
    int solve(int maxor,int cor,int i,vector<int> nums){
        if(i==nums.size()){
            return cor==maxor?1:0;
        }
        if(dp[i][cor]!=0){
            return dp[i][cor];
        }
        return dp[i][cor]=solve(maxor,cor,i+1,nums)+solve(maxor,cor|nums[i],i+1,nums);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxor=0;
        for(int i=0;i<nums.size();i++){
            maxor|=nums[i];
        }
        
        return solve(maxor,0,0,nums);
    }
};