class Solution {
public:
    
    int minCut(string s) {
        int n=s.length();
      vector<vector<int>> dp(n,vector<int>(n,0));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;j++,i++){
                if(g==0){
                    dp[i][j]=1;
                }
                else if(g==1){
                    dp[i][j]=s[i]==s[j];
                }else{
                    dp[i][j]=s[i]==s[j] && dp[i+1][j-1];
                }
            }
        }
        
        vector<int> res(n,0);
        res[0]=0;
        for(int j=1;j<n;j++){
            int mini=INT_MAX,f=0;
            for(int i=j;i>=0;i--){
                if(dp[i][j]){
                    if(i==0){
                        f=1;
                        continue;
                    }
                    mini=min(mini,res[i-1]);
                }
            }
            res[j]=f==1?0:mini+1;
        }
        return res[n-1];
    }
};