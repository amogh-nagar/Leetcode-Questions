class Solution {
public:
    long long appealSum(string s) {
        long long ans=0,c=0;
        vector<int>prev(26,-1);
        map<char,int> m;
        for(int i=0;i<s.length();i++){
            c+=(i-prev[s[i]-'a']);
            prev[s[i]-'a']=i;
            ans+=c;
        }
        return ans;
    }
};