class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int c=0,currsum=0,n=nums.size();
        map<int,int> m;
        m.insert({0,1});
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            if(m.find(currsum-k)!=m.end()){
                c+=m[currsum-k];
            }
             m[currsum]++;
        }
        return c;
    }
};