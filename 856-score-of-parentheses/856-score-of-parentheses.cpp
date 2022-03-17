class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(0);
            }else{
                if(st.top()==0){
                    st.pop();
                    st.push(1);
                    continue;
                }
                int c=0;
                while(!st.empty() && st.top()!=0){
                    c+=st.top();
                    st.pop();
                }
                st.pop();
                st.push(2*c);
            }
        }
        int c=0;
        while(!st.empty()){
            c+=st.top();
            st.pop();
        }
        return c;
    }
};