class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size(),mx=0,tx=0,ma=0,ta=0;
        for(int i=0;i<n;i++){
            tx+=nums[i];
            ta+=nums[i];
            mx=min(mx,tx);
            ma=max(ma,ta);
            if(tx>0){
                tx=0;
            }
            if(ta<0){
                ta=0;
            }
        }
        return max(abs(mx),ma);
    }
};