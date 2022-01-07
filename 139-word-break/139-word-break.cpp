class Solution {
public:
    
    map<string,int> m;
    bool solve(string s, vector<string>& wordDict,set<string> se) {
        if(s.length()==0){
            return true;
        }
        if(m.find(s)!=m.end()){
            return m[s];
        }
        int y=0;
        string x;
        for(int i=0;i<s.length();i++){
            x+=s[i];
            if(se.find(x)!=se.end()){
                y+=solve(s.substr(i+1),wordDict,se);
                
            }
        }
        m.insert({s,y});
        return y; 
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> se;
        for(int i=0;i<wordDict.size();i++){
            se.insert(wordDict[i]);
        }
        return solve(s,wordDict,se);
    }
};