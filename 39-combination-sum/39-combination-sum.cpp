class Solution {
public:
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      
        vector<vector<vector<int>>> dp(target+1);
        
        for(auto c:candidates){
            for(int i=1;i<=target;i++){
                if(i>=c){
                if(i==c){
                    dp[i].push_back({c});
                }else{
                   for(auto v:dp[i-c]){
                       v.push_back(c);
                       dp[i].push_back(v);
                   }
                }}
            }
        }
        return dp[target];
        
    }
};