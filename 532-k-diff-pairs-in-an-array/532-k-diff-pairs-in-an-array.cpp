class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> m;
        int c=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            
        }
        
        for(auto it:m){
            if(k==0){
                if(it.second>=2){
                    c++;
                }
            }else if(m.find(it.first+k)!=m.end()){
                c++;
            }
        }
        return c;
    }
};