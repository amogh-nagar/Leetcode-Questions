class Solution {
public:
    
    bool check(int m,vector<int> nums,int th){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%m==0){
                sum+=(nums[i]/m);
            }else{
                sum+=((nums[i]+m)/m);
            }
        }
        return sum<=th;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,ans=0,h=*max_element(nums.begin(),nums.end());
        while(l<=h){
            int m=l+(h-l)/2;
            if(check(m,nums,threshold)){
                ans=m;
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};