class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask=0,maxx=0;
        for(int i=31;i>=0;i--){
            mask|=(1<<i);
            set<int> s;
            for(int i=0;i<nums.size();i++){
                s.insert(nums[i] & mask);
            }
            
            
            int newm=maxx | (1<<i);
            
            for(auto prefix:s){
                if(s.find(prefix ^ newm)!=s.end()){
                    maxx=newm;
                    break;
                }
            }
        }
        return maxx;
    
    }
};