class Solution {
public:
    bool isvalid(string s){
        if(s[0]=='0'){
            return false;
        }
        if(s.length()==1){
            return true;
        }
        if(s>="1" && s<="26"){
            return true;
        }
        return false;
    }
    
    int numDecodings(string s) {
        if(s.length()==1){
           if(s[0]=='0'){
            return false;
           }
           return true; 
        }
        vector<int> dp(s.length(),0);
        if(isvalid(s.substr(0,1))){
            dp[0]=1;
        }
        
        if(isvalid(s.substr(1,1))){
            dp[1]=dp[0];
        }
        if(isvalid(s.substr(0,2))){
            dp[1]++;
        }
        for(int i=2;i<s.length();i++){
            string x=s.substr(i-1,2);
            if(isvalid(x)){
                dp[i]+=dp[i-2];
            }
            if(isvalid(s.substr(i,1)))
                dp[i]+=dp[i-1];
        }
        return dp[s.length()-1];
    }
};