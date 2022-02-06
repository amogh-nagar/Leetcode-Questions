class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int l=0,m=0;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            int x=*s.begin();
            int y=*s.rbegin();
            if((y-x)>limit){
              int diff=y-x;
                while(diff>limit){
                    auto x=s.find(nums[l]);
                    s.erase(x);
                    diff=*s.rbegin()-*s.begin();
                    l++;
                }
                // cout<<i<<" "<<l<<endl;
               
            }
             m=max(m,i-l+1);
        }
    return m;
    }
};