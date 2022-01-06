class Solution {
public:
    
    int solve(int start,vector<int> nums,int currxor){
        if(start>=nums.size()){
            return 0;
        }
        int x=0;
        for(int i=start;i<nums.size();i++){
        
            x+=(currxor^nums[i]);
            x+=solve(i+1,nums,currxor^nums[i]);
        }
        return x;
    }
    
    
    int subsetXORSum(vector<int>& nums) {
        return solve(0,nums,0);
    }
};