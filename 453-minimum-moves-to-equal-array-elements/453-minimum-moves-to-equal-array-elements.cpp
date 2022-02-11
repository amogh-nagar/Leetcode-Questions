class Solution {
public:
    int minMoves(vector<int>& nums) {
        int x=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            x+=(nums[i]-nums[0]);
        }
        return x;
    }
};