class Solution {
public:
    bool static comp(string a, string b){
        return a.length()>b.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        unordered_set<string> s;
        int res=0;
        for(auto x:words){
            if(s.find(x)!=s.end())
                continue;
            for(int i=0;i<x.length();i++){
                s.insert(x.substr(i,x.length()-i));
            }
            res+=(x.length()+1);
        }
        return res;
    }
};