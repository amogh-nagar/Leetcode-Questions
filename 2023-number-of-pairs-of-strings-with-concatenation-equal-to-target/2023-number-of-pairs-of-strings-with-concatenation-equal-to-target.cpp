class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int c=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if((nums[i]+nums[j])==target){
                    c++;
                }
                if(nums[j]+nums[i]==target){
                    c++;
                }
            }
        }
        return c;
    }
};