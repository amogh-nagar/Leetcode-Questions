class Solution {
public:
    unordered_map<string,int> dp;
    
    int numDecodings(string s) {
        if(s.size()==0){
            return 1;
        }
        if(dp[s]!=0){
            return dp[s];
        }
        int c=0;
        string t="";
        for(int i=0;i<s.length();i++){
            t+=s[i];
            
            if(stoi(t)>=1 && stoi(t)<=26){
                c+=numDecodings(s.substr(i+1));
            }else{
                break;
            }
        }
        return dp[s]=c;
    
    }
};