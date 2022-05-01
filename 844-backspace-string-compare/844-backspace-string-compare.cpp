class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a,b;
        for(int i=0;i<s.length();i++){
            if(s[i]!='#'){
                a+=s[i];
            }else{
                if(a.length()>0)
                a.pop_back();
            }
        }
        
        for(int i=0;i<t.length();i++){
            if(t[i]!='#'){
                b+=t[i];
            }else{
                if(b.length()>0)
                b.pop_back();
            }
        }
        return a==b;
    }
};