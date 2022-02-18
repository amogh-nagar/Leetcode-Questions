class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<vector<string>> dp(s.length());
        if(isalpha(s[0])){
        dp[0].push_back(string(1,tolower(s[0])));
        dp[0].push_back(string(1,toupper(s[0])));
            
        }else{
            dp[0].push_back(string(1,s[0]));
        }
        for(int i=1;i<s.length();i++){
            if(isalpha(s[i])){
            for(auto x:dp[i-1]){
                dp[i].push_back(x+string(1,tolower(s[i])));
            }
            for(auto x:dp[i-1]){
                dp[i].push_back(x+string(1,toupper(s[i])));
            }
            }else{
                
            for(auto x:dp[i-1]){
                dp[i].push_back(x+string(1,s[i]));
            }
            }
        }
        return dp[s.length()-1];
    }
};