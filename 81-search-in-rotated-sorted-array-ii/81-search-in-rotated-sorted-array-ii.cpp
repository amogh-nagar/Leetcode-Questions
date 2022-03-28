class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,n=nums.size(),h=nums.size()-1;
        while(l<=h){
            while(l<h && nums[l]==nums[l+1])l++;
            while(h>l && nums[h]==nums[h-1])h--;
            int m=(l+h)/2;
            if(nums[m]==target){
                return true;
            }
            if(nums[l]<=nums[m]){
                if(nums[l]<=target && nums[m]>target){
                    h=m-1;
                }else{
                    l=m+1;    
                }
            }else{
                if(nums[h]>=target && target>nums[m]){
                    l=m+1;
                }else{
                    h=m-1;
                }
            }
            // cout<<l<<" "<<h<<endl;
            
        }
        return false;
    }
};