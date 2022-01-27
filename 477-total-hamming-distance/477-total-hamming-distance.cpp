class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int c=0;
        for(int j=31;j>=0;j--){
            int o=0,z=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i] & (1<<j)){
                    o++;
                }else{
                    z++;
                }
            }
            if(o!=0 && z!=0){
                c+=(o*z);
            }
        }
        return c;
    }
};