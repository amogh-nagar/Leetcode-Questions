class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      
        map<int,int> m;
        int c=0,currsum=0;
        m.insert({0,0});
        for(int i=0;i<nums.size();i++){
            c++;
            if(nums[i]!=0){
             
            currsum+=nums[i];
            
            if(m.find(currsum%k)!=m.end()){
                if(c-m[currsum%k]>=2)
                 return true;
                
            }
            else
                m[currsum%k]=c;
               
            }else{
                if(i>0 && nums[i-1]==0||i<nums.size()-1 && nums[i+1]==0){
                    return true;
                }
            }
        }
        return false;
    }
};