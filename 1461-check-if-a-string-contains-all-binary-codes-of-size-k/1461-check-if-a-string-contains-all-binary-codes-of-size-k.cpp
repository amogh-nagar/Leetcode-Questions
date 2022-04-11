class Solution {
public:
    typedef long long int ll;
    bool hasAllCodes(string s, int k) {
        if(s.length()<k){
            return false;
        }
        unordered_set<ll> st;
        int i=0,j=0;
        ll c=0;
        for(j=k-1;j>=0;j--){
            c=c+(s[j]-'0')*pow(2,i++);
        }
        st.insert(c);
        i=1,j=k;
        for(; j<s.length();j++){
            ll x=~(1<<(k-1));
            c=c&x;
            c<<=1;
            c=c|s[j]-'0';
            st.insert(c);
        }
        return st.size()==(1<<k);
    }
    
};