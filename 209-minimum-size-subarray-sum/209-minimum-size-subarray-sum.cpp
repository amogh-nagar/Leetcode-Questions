class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int x=0,i=0,mi=INT_MAX;
        for(int j=0;j<nums.size();j++){
            x+=nums[j];
           
        while(x>=target){
            
           mi=min(mi,j-i+1);
            x-=nums[i];
            i++;
        }
        }
        return mi!=INT_MAX?mi:0;
    }
};