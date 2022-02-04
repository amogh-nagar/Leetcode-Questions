class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(),m=0,pi=0,pj=0;
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    dp[i][j]=true;
                }else if(g==1){
                    
                    dp[i][j]=s[i]==s[j];
                }else{
                    dp[i][j]=s[i]==s[j] && dp[i+1][j-1];
                }
                if(dp[i][j] && (j-i+1)>m){
                    m=j-i+1;
                    pj=j;
                    pi=i;
                }
            }
        }
        return s.substr(pi,m);
    }
};