class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0;
        int p=1,c=0;
        while(j<nums.size() && i<nums.size()){
            p*=nums[j];
            while(p>=k && i<nums.size()){
                p/=nums[i];
                i++;
            }
            if(p<k){
                c+=(j-i+1);
            }
            j++;
        }
        return c;
    }
};