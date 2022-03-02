class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        if(s.length()>t.length())
            return false;
        while(j<t.length() && i<s.length()){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==s.length();
    }
};