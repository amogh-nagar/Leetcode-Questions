class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> m;
        int c=0,currsum=0;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            int x=(currsum%k+k)%k;
            if(m.find(x)!=m.end()){
                c+=m[x];
                   
            }
            m[x]++;
        }
        return c;
    }
};