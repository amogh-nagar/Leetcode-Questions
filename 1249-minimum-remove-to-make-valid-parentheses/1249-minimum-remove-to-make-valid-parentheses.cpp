class Solution {
public:
    string minRemoveToMakeValid(string s) {
       stack<pair<char,int>> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push({s[i],i});
            }
            else if(s[i]==')'){
                if(!st.empty() && st.top().first=='('){
                    st.pop();
                }else{
                    st.push({s[i],i});
                }
            }
        }
        string res;
        for(int i=s.length()-1;i>=0;i--){
            if(!st.empty() && i==st.top().second){
                st.pop();
            }else{
                res+=s[i];
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};