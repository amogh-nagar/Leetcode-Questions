class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int x=0;
        if(n%2==0){
            x=(nums[n/2]+nums[(n-1)/2])/2;
        }else{
            x=nums[n/2];
        }
        int c=0;
        for(int i=0;i<nums.size();i++){
            c+=(abs(x-nums[i]));
        }
        return c;
    }
};