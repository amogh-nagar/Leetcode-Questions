class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
        int maxi=0,l=0;
        for(int g=0;g<s.length();g++){
            for(int i=0,j=g;j<s.length();j++,i++){
                if(g==0){
                    dp[i][j]=1;
                }else if(g==1){
                    dp[i][j]=(s[i]==s[j]);
                }else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j]==1 && maxi<(j-i+1)){
                    
                     maxi=j-i+1;
                     l=i;
                    
                }
            }
        }
        return s.substr(l,maxi);
    }
};