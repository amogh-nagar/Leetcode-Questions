class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c=0,j=nums.size();
        int pos=0,prev=nums[0];
        c=1;
        for(int i=1;i<j;i++){
            if(prev!=nums[i]){
                nums[++pos]=nums[i];
                prev=nums[i];
                c=1;
            }else if(c<2){
            
                nums[++pos]=nums[i];
                c++;
            }
        }
        return pos+1;
    }
};