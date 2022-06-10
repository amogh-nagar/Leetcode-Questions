class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int maxi=0;
        for(int i=0,j=0;j<s.length();j++){
            while(i<j && m[s[j]]>0){
                m[s[i]]--;
                i++;
            }
            m[s[j]]++;
            maxi=max(maxi,j-i+1);
        }
        return maxi;
    }
};