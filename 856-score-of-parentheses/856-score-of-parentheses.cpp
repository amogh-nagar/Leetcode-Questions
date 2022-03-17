class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int> st;
        stack<pair<int,int>> s1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                if(i-st.top()==1){
                    
                    s1.push({1,st.top()});
                    st.pop();
                    continue;
                }
                int x=st.top();
                st.pop();
                int c=0;
                while(!s1.empty() && s1.top().second>=x){
                    c+=s1.top().first;
                    s1.pop();
                }
                s1.push({c*2,x});
            }
        }
        int c=0;
        while(!s1.empty()){
            c+=s1.top().first;
            s1.pop();
        }
        return c;
    }
};