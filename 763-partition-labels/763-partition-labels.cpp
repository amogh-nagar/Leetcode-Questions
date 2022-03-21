class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> hashmap;
        for(int i=0;i<s.length();i++){
            hashmap[s[i]]++;
        }
        set<pair<char,int>> st;
        vector<int> t(256,0);
        int c=1;
        vector<int> res;
        int i=0;
        while(hashmap[s[i]]==1 && i<s.length()){
            res.push_back(1);
            i++;
        }
        if(i==s.length()){
            return res;
        }
        st.insert({s[i],1});
        t[s[i]-'a']=1;
        i++;
        for(;i<s.length();i++){
            if(st.size()==0){
            cout<<"c: "<<c<<endl;
                res.push_back(c);
                c=0;
            }
            
            
            if(t[s[i]-'a']==0){
                if(hashmap[s[i]]!=1)
                {st.insert({s[i],1});
            // cout<<s[i]<<" "<<i<<endl;    
                 t[s[i]-'a']=1;
                }
            }
            else{
                auto it=st.find({s[i],t[s[i]-'a']});
                if(it->second==hashmap[s[i]]-1){
                    // cout<<"delketd: "<<it->first<<" "<<it->second<<endl;
                    st.erase(it);
                
                }
                else{
                    int x=it->second;
                    st.erase(it);
                    st.insert({s[i],x+1});
                    t[s[i]-'a']+=1;
                }
            }
            
            c++;
        }
        res.push_back(c);
        return res;
    }
};