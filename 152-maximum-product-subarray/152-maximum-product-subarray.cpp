class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ma=1,m=INT_MIN,mi=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
              swap(ma,mi);
            }
            if(nums[i]==0){
                m=max(m,nums[i]);
                ma=mi=1;
            }
            else{
                ma=max(nums[i],nums[i]*ma);
                mi=min(nums[i],nums[i]*mi);
                m=max(m,ma);
            }
        }
        return m;
    }
};