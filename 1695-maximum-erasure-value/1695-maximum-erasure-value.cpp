class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxi=0,s=0;
        map<int,int> m;
        for(int i=0,j=0;j<nums.size();j++){
            while(i<j && m[nums[j]]>0){
                m[nums[i]]--;s-=nums[i];i++;
            }
            m[nums[j]]++;
            s+=nums[j];
            maxi=max(s,maxi);
        }
        return maxi;
    }
};