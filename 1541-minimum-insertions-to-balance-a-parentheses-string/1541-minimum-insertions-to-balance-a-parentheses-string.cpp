class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int t=0,n=s.length();
        for(int i=0;i<s.length();i++){
               if(s[i]=='('){
                   st.push(s[i]);
               }else{
                   if((st.empty() && ((i+1<n && s[i+1]!=')')||(i==n-1)))){
                       t+=2;
                       
                   }else{
                       if(!st.empty() && i+1<n &&  s[i+1]==')'){
                           i++;
                           st.pop();
                           continue;
                       }
                       if(st.empty() && i+1<n && s[i+1]==')'){
                           t++;i++;
                       }
                      
                       else if((st.top()=='(' && i+1<n && s[i+1]!=')')){
                           t++;
                           st.pop();
                       }else if(st.top()=='(' && i==n-1){
                           t++;
                           st.pop();
                       }
                       
                   }
               }
        }
        while(!st.empty()){
            t+=2;
            st.pop();
        }
        return t;
    }
};