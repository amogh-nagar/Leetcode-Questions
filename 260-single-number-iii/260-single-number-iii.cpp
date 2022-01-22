class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0,idx=0;
        for(int i=0;i<nums.size();i++){
            xr^=nums[i];
        }
        for(int i=0;i<32;i++){
            if(xr & 1<<i){
                idx=i;
                break;
            }
        }
        int first=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & 1<<idx){
                first^=nums[i];
            }
        }
        int second=xr^first;
        return {first,second};
    }
};