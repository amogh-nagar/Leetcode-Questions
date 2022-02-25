class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int n=nums.size(),l=0,h=nums.size()-1;
        while(l<=h){
            int m=(l+h)/2;
            if((m==0 && nums[m]!=nums[m+1])||(m==n-1 && nums[m]!=nums[m-1])||(nums[m]!=nums[m-1] && nums[m]!=nums[m+1])){
                return  nums[m];
            }
            if(nums[m]==nums[m+1] && (m%2==0)){
                l=m+1;
            }else if(nums[m]==nums[m+1] && (m%2!=0)){
                h=m-1;
            }else if(nums[m]==nums[m-1] && (m%2!=0)){
                l=m+1;
            }else if(nums[m]==nums[m-1] && (m%2==0)){
                h=m-1;
            }
            
            
        }
        return 0;
        
    }
};