class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        map<int,int> m;
        int n=nums.size();
        for(int i=0;i<(1<<nums.size());i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    count|=nums[j];
                }
            }
            m[count]++;
        }
        return m.rbegin()->second;
    }
};