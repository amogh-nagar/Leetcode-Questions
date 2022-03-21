class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]=i;
        }
        vector<int> res;
        int x=0,mi=0;
        
        for(int i=0;i<s.length();i++){
            if(m[s[i]]==mi && i==mi){
                res.push_back(mi-x+1);
                mi++;
                x=mi;
                continue;
            }
            mi=max(mi,m[s[i]]);
        }
        return res;
    }
};