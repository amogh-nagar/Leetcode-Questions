class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,c=0,j=0,maxl=INT_MIN;
        for(;j<nums.size();j++){
            if(nums[j]==0){
                c++;
            }
            if(c>k){
                while(c>k){
                 
                if(nums[i]==0){
                    c--;
                    
                }
                   i++;
                }
            }
            
               maxl=max(maxl,j-i+1);
            
        }
        return maxl;
    }
};