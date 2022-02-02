class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length()<p.length()){
            return {};
        }
        vector<int> hash(26,0);
        vector<int> phash(26,0);
        for(int i=0;i<p.length();i++){
            hash[s[i]-'a']++;
            phash[p[i]-'a']++;
        }
        vector<int> res;
        if(hash==phash){
            res.push_back(0);
        }
        for(int i=p.length();i<s.length();i++){
            hash[s[i]-'a']++;
            hash[s[i-p.length()]-'a']--;
            if(hash==phash){
                res.push_back(i-p.length()+1);
            }
        }
        return res;
    }
};