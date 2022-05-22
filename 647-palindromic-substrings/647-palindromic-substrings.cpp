class Solution {
public:
    int countSubstrings(string s) {
        bool dp[s.length()+1][s.length()+1];
        memset(dp,0,sizeof(dp));
        int n=s.length(),c=0;
        for(int i=n;i>=1;i--){
            for(int j=n;j>=1;j--){
                
                if(i==j){
                    dp[i][j]=1;
                }
                else if(i<j){
                    if((i+1)>(j-1)){
                        dp[i][j]=(s[i-1]==s[j-1]);
                    }
                    else
                    dp[i][j]=(s[i-1]==s[j-1]) && dp[i+1][j-1];
                    
                }
                c+=dp[i][j];
            }
        }
        
        return c;
    }
};