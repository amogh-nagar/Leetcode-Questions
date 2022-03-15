class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push({s[i],i});
            }else if(s[i]==')'){
                if(!st.empty() && st.top().first=='('){
                    st.pop();
                }else{
                    st.push({s[i],i});
                }
            }
        }
        while(!st.empty()){
            s[st.top().second]='*';
            st.pop();
            
        }
        string res;
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'){
                
                res+=s[i];
            }
        }
        return res;
    }
};