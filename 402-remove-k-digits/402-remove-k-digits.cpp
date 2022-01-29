class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int n=num.length();
        if(n==k){
            return "0";
        }
        st.push(num[0]-'0');
        for(int i=1;i<n;i++){
            while(!st.empty() && k>0 && (num[i]-'0')<st.top()){
                k--;
                
                st.pop();
            }
            if(st.empty() && num[i]=='0'){
                continue;
            }
            st.push(num[i]-'0');
        }
        while(!st.empty() && k>0){
            st.pop();k--;
        }
        if(st.empty()){
            return "0";
        }
        string res;
        while(!st.empty()){
            res+=st.top()+'0';
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};