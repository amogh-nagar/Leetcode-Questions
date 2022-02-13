class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> t,vector<int>& nums,int idx,int n){
        if(idx==n){
          res.push_back(t);
            return;
        }
        t.push_back(nums[idx]);
        solve(t,nums,idx+1,n);
        t.pop_back();
        int x=nums[idx];
        idx++;
        while(idx<n && nums[idx]==x)idx++;
        solve(t,nums,idx,n);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        vector<int> t;
       solve(t,nums,0,nums.size());
        return res; 
    }
};