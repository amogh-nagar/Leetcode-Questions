class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> result;
        int maxi=INT_MIN,f=0,n=nums.size();
        vector<pair<int,int>> res;
        for(int i=0;i<n;i++){
            res.push_back({-1,0});
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(res[i].second<=res[j].second){
                if(nums[i]%nums[j]==0){
                    
                    res[i].first=j;
                    res[i].second=res[j].second+1;
                }}
            }
            if(maxi<res[i].second){
                maxi=res[i].second;
                f=i;
            }
        }
        while(f>=0){
            result.push_back(nums[f]);
            f=res[f].first;
        }
        return result;
    }
};