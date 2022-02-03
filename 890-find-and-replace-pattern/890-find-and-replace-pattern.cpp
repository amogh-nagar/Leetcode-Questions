class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        int n=words.size();
        for(int i=0;i<n;i++){
            map<char,char> m1,m2;
            string x=words[i];
            int f=0;
            for(int j=0;j<x.length();j++){
                if(m1.find(x[j])==m1.end() && m2.find(pattern[j])==m2.end()){
                    m1[x[j]]=pattern[j];
                    m2[pattern[j]]=x[j];
                }
                else if(m2[pattern[j]]!=x[j]){
                    f=1;
                    break;
                }else if(m1[x[j]]!=pattern[j]){
                    f=1;
                    break;
                }
            }
            if(!f){
                res.push_back(x);
            }
        }
        return res;
    }
};