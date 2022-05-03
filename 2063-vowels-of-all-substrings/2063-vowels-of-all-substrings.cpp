class Solution {
public:
    typedef long long int ll;
    long long countVowels(string word) {
        vector<ll> dp(word.length()+1,0);
        for(int i=1;i<=word.length();i++){
            if(word[i-1]=='a'||word[i-1]=='e'||word[i-1]=='i'||word[i-1]=='o'||word[i-1]=='u'){
                dp[i]=dp[i-1]+i;
            }else{
                dp[i]=dp[i-1];
            }
        }
        ll s=0;
        for(auto x:dp){
            s+=x;
        }
        return s;
    }
};