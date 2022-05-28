class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(i==nums[i]){
                i++;
            }else{
                if(nums[i]<=(nums.size()-1)){
                    swap(nums[i],nums[nums[i]]);
                }else{
                    i++;
                }
            }
        }
        i=0;
        while(i<nums.size()){
            if(i!=nums[i]){
                return i;
            }
            i++;
        }
        return i;
    }
};