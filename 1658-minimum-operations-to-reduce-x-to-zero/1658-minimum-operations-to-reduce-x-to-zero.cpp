class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i=0,j=nums.size()-1;
        int s=0,minlen=INT_MAX;
        while(i<nums.size()){
            if(s<x){
                s+=nums[i];
                i++;
            }else{
                break;
            }
        }
        if(i==nums.size()){
            if(s==x)
            return nums.size();
            else
              return -1;  
        }
        i--;
        minlen=s==x?i+1:INT_MAX;
        s+=nums[j--];
        while(j>=0){
            
            if(s==x){
                if(minlen>i+1+nums.size()-j-1){
                    minlen=i+1+nums.size()-j-1;
                }
            }
            if(s>x){
                if(i>=0)
                 s-=nums[i--];
                else
                    break;
            }else{
                s+=nums[j--];
            }
        }
        return minlen==INT_MAX?-1:minlen;
        
    }
};