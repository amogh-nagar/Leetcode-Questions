class Solution {
public:
    vector<vector<string>> partition(string s) {
         vector<vector<string>> res;
        vector<string> v;
        solve(s,res,v,0);
        return res;
    }
    bool check(int start,int end,string s){
         while(start<end){
              if(s[start++]!=s[end--]){
                  return false;
              }
          }
        return true;
    }
    void solve(string s,vector<vector<string>>&res,vector<string> &v,int start){
        if(start>=s.length()){
            res.push_back(v);
            return;
        }
        for(int end=start;end<s.length();end++){
            if(check(start,end,s)){
                v.push_back(s.substr(start,end-start+1));
                solve(s,res,v,end+1);
                v.pop_back();
            }
            
        }
        return;
    }
};