class Solution {
public:
    bool isValidSerialization(string s) {
        int n=s.length();
        if(s[0]=='#'){
            if(n==1)
            return true;
            else return false;
        }
        int i=0;
        stack<pair<int,pair<int,int>>> st;
        string x;
        while(i<s.length() && s[i]!=','){
            x+=s[i];
            i++;
        }
        st.push({stoi(x),{1,1}});
        for(;i<s.length();i++){
            if(s[i]==',')
                continue;
            if(s[i]=='#'){
                
                if(st.empty()){
                    if(s.length()==1){
                        return true;
                    }else{
                        return false;
                    }
                }
                if(!st.empty() && st.top().second.first>0){
                    st.top().second.first*=-1;
                }else if(!st.empty() && st.top().second.second>0){
                    while(!st.empty() && st.top().second.first==-1){
                        st.pop();
                    }
                    if(!st.empty()){
                        st.top().second.first*=-1;
                    }
                }
            }else{
                if(st.empty())
                    return false;
                string x;
                while(i<s.length() && s[i]!=','){
                    x+=s[i];
                    i++;
                }
                st.push({stoi(x),{1,1}});
            }
            
        }
        return st.empty();
    }
};