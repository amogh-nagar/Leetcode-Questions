class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int mask=0;
        for(int i=0;i<32;i++){
           int orgc=0,ac=0;
           for(int j=0;j<nums.size();j++){
               if((1<<i) & j){
                   orgc++;
               }
               if((1<<i) & nums[j]){
                   ac++;
               }
           }
           if(ac>orgc){
               mask=mask | (1<<i);
           }
       } 
       return mask; 
    }
};