class Solution {
public:
    long long appealSum(string s) {
        long long ans=0;
        vector<int> prev(26,-1);
        for(int i=0;i<s.length();i++){
            ans+=((i-prev[s[i]-'a'])*(s.length()-i));
            prev[s[i]-'a']=i;
        }
        return ans;
    }
};