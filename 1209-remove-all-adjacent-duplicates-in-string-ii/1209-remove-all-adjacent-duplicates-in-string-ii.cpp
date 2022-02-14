class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        
        for(int i=0;i<s.length();i++){
            if(!st.empty() && (st.top().first==s[i])){
                if(st.top().second+1!=k){
                    pair<int,int> t=st.top();
                    st.pop();
                   st.push({s[i],t.second+1});
                 
                }
                   
                else if(st.top().second==k-1){
                        st.pop();
                }
            }else{
                st.push({s[i],1});
            }
        }
        
        string res;
        while(!st.empty()){
            int x=st.top().second;
        string str(st.top().second,st.top().first);
             res=res+str;
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};