class Solution {
public:
    bool static comp(string a,string b){
        return a.length()<b.length();
    }
    bool isvalid(string x,string y){
        if(x.length()+1!=y.length()){
            return false;
        }
        int i=0,j=0,c=0;
        while(i<x.size() && j<y.size()){
            if(x[i]!=y[j]){
                c++;
            }else{
                i++;
            }
            
            j++;
        }
        return (c==1 && i==x.length() && j==y.length())||(c==0 && i==x.length() && j==y.length()-1);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        vector<int> dp(words.size(),1);
        int maxi=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(isvalid(words[j],words[i])){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};