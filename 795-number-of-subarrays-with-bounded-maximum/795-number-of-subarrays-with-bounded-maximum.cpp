class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int l=0,r=0,c=0,x=0;
        while(r<nums.size()){
            if(nums[r]>right){
                l=r+1;
                x=0;
            }else if(nums[r]>=left && nums[r]<=right){
                x=(r-l+1);
                c+=x;
            }else if(nums[r]<left){
                c+=x;
            }
            
            r++;
        }
        return c;
    }
};