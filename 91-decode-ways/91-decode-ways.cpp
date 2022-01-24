class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0'){
            return 0;
        }
        if(s.length()==1){
            return 1;
        }
        
        vector<int> dp(s.length()+1,0);
        int n=s.length();
        dp[1]=1;
        dp[0]=1;
        for(int i=2;i<=n;i++){
            
            
            string x=s.substr(i-2,2);
            char c=s[i-1]-'0';
            if(c!=0){
                dp[i]=dp[i-1];
            }
            if(stoi(x)<=26 && stoi(x)>=10){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};