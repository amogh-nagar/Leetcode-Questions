class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            v.push_back(((nums[i]*(i+1))-prefix[i])+(prefix[n-1]-prefix[i]-(nums[i]*(n-1-i))));
        }
        return v;
    }
};