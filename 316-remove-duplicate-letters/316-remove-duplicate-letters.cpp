class Solution {
public:
    string removeDuplicateLetters(string s) {
     
        unordered_map<char,int> m;
        string ans;
        for(int i=0;i<s.length();i++){
            m[s[i]]=i;
        }
        
        vector<bool> v(26,false);
        for(int i=0;i<s.length();i++){
            if(v[s[i]-'a']){
                continue;
            }
            
            while(ans.size()>0 && ans.back()>s[i] && m[ans.back()]>i){
                v[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            v[s[i]-'a']=true;
        }
        return ans;
        
    }
};