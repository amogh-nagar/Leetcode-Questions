class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int i=0,j=nums.size()-1;
        sort(nums.begin(),nums.end());
        int c=0;
        while(i<j){
            if(nums[j]+nums[i]>k){
                j--;
            }else if(nums[i]+nums[j]==k){
                c++;
                i++;
                j--;
            }else if(nums[i]+nums[j]<k){
                i++;
            }
        }
        return c;
    }
};