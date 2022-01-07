class Solution {
public:
    int specialArray(vector<int>& nums) {
        int l=1,ans=-1,h=nums.size();
        sort(nums.begin(),nums.end());
        while(l<=h){
            int m=(l+h)/2;
            auto y=lower_bound(nums.begin(),nums.end(),m);
            int x=y-nums.begin();
            if(nums.size()-x==m){
                return m;
            }
            if(nums.size()-x>m){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return -1;
    }
};