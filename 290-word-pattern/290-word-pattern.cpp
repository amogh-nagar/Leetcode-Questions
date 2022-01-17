class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> m;
        int j=0;
        map<string,char> m1;
        for(int i=0;i<pattern.length();i++){
            string res;
            int k=0;
            for( k=j;k<s.length();k++){
                if(s[k]==' ')
                    break;
                
                res+=s[k];
            }
            j=k+1;
            if((m1.find(res)!=m1.end() && m1[res]!=pattern[i])){
                return false;
            }
            if(m.find(pattern[i])==m.end()&&m1.find(res)==m1.end()){
                
                m.insert({pattern[i],res});
            m1.insert({res,pattern[i]});
            }
            else if(m[pattern[i]]!=res){
                return false;
            }
            
        }
        if(j-1!=s.length()){
            return false;
        }
        return true;
    }
};