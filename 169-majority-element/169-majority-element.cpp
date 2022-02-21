class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=1,m=nums[0];
        for(int i=1;i<nums.size();i++){
            if(m==nums[i]){
                c++;
            }else{
                c--;
            }
            
            if(c<0){
                m=nums[i];
                c=1;
            }
        }
        c=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==m){
               c++;
           }
        }
        if(c>(nums.size()/2)){
            return m;
        }
        return 0;
    }
};