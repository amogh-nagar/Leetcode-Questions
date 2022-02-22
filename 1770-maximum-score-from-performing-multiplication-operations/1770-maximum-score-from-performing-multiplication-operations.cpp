class Solution {
public:
    int dp[1001][1001];
    int solve(int l,int idx,vector<int>& nums, vector<int>& mult){
        if(idx==mult.size()){
            return 0;
        }
        if(dp[l][idx]!=-1){
            return dp[l][idx];
        }
        int left=mult[idx]*nums[l] + solve(l+1,idx+1,nums,mult);
        int right=mult[idx]*nums[nums.size()-1-(idx-l)] + solve(l,idx+1,nums,mult);
        return dp[l][idx]=max(left,right);
        
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multi) {
       
        int n=nums.size();
        int m=multi.size();
        
        memset(dp,0,sizeof(dp));
        for(int i=m-1;i>=0;i--){
            for(int l=i;l>=0;l--){
                int right=nums[nums.size()-1-(i-l)] * multi[i]+dp[l][i+1];
                dp[l][i]=max(nums[l]*multi[i]+dp[l+1][i+1],right);
            }
        }
        return dp[0][0];
        
        
        
    }
};