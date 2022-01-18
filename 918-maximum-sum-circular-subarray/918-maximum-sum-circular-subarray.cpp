class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int min_straight=INT_MAX,max_straight=INT_MIN;
        int temp_max=0,temp_min=0,total=0;
        for(int i=0;i<nums.size();i++){
            temp_max+=nums[i];
            max_straight=max(max_straight,temp_max);
            if(temp_max<=0){
                temp_max=0;
            }
            
            
            temp_min+=nums[i];
            min_straight=min(min_straight,temp_min);
            
            if(temp_min>0){
                temp_min=0;
            }
            
            
            
            total+=nums[i];
        }
        
        if(total==min_straight)
            return max_straight;
        
        return max(max_straight,total-min_straight);
    }
};