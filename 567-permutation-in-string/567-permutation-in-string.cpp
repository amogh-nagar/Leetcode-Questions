class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m1(26,0),m2(26,0);
        int i=0;
        if(s1.length()>s2.length()){
            return false;
        }
        for(i=0;i<s1.length();i++){
            m1[s1[i]-'a']++;
            m2[s2[i]-'a']++;
        }
        int j=0;
        for(;i<s2.length();i++){
            if(m1==m2){
                return true;
            }
            m2[s2[i]-'a']++;
            m2[s2[j++]-'a']--;
        }
         if(m1==m2){
                return true;
            }
        return false;
    }
};