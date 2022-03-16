class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       
        int l=0,n=nums.size(),r=n-1;
        for(;l<n-1;l++){
            if(nums[l]>nums[l+1]){
                break;
            }
        }
        if(l==n-1){
            return 0;
        }
        for(;r>0;r--){
            if(nums[r]<nums[r-1]){
                break;
            }
        }
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=l;i<=r;i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        int i=0;
        for(;i<l;i++){
            if(mini<nums[i]){
                break;
            }
        }
        l=i;
        for(i=n-1;i>r;i--){
            if(maxi>nums[i]){
                break;
            }
        }
        r=i;
        return r-l+1;
    }
};