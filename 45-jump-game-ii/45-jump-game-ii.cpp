class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0,max_jump=INT_MIN,curr_reach=0;
        for(int i=0;i<nums.size()-1;i++){
            max_jump=max(max_jump,nums[i]+i);
            if(i>curr_reach){
                return -1;
            }
            if(curr_reach==i){
                curr_reach=max_jump;
                jump++;
            }
        }
        return jump;
    }
};