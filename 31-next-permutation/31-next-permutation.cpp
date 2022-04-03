class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0){
            if(nums[i]<nums[i+1])
                break;
            i--;
        }
        if(i==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        int j=nums.size()-1;
        while(j>i){
            if(nums[j]>nums[i]){
                break;
            }
            j--;
        }
        swap(nums[i],nums[j]);
        sort(nums.begin()+i+1,nums.end());
        
        
    }
};