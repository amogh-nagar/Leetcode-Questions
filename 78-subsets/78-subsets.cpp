class Solution {
public:
    void solve(vector<vector<int>> &res,vector<int>& v,vector<int> nums,int i){
        if(i==nums.size()){
            res.push_back(v);
            return;
        }
            
            
            
        v.push_back(nums[i]);
        solve(res,v,nums,i+1);
        v.pop_back();
        
        solve(res,v,nums,i+1);
        return;
    }
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        solve(res,v,nums,0);
        return res;
    }
};