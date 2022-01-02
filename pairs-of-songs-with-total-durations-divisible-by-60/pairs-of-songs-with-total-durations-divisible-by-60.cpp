class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& nums) {
                map<int,int> m;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%60==0){
                if(m[0]!=0){
                    c+=m[0];
                }
            }
            
            else if(m.find(60-(nums[i]%60))!=m.end()){
             c+=m[60-(nums[i]%60)];   
            }
            
            m[nums[i]%60]++;
        }
        return c;

    }
};