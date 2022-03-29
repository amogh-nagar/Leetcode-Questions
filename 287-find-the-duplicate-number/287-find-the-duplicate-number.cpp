class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l=1,ans=0,h=nums.size()-1;
        while(l<=h){
            int m=(l+h)/2;
            int c=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<=m){
                    c++;
                }
            }
            if(c<=m){
                l=m+1;
            }else{
                ans=m;
                h=m-1;
            }
        }
        return ans;
    }
};