class Solution {
public:
    int longestValidParentheses(string s) {
        int c=0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                if(!st.empty() && st.top()>=0 && s[st.top()]=='('){
                    st.pop();
                    c=max(c,i-st.top());
                }else{
                    st.push(i);
                }
            }
        }
        return c;
    }
};