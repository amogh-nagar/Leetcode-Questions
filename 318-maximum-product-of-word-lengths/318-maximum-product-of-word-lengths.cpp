class Solution {
public:
    typedef long long int ll;
    typedef long double ld;
    ll max(ll a , ll b){if(a > b) return a ; return b ;}
    ll min(ll a , ll b){if(a < b) return a ; return b ;}

    int maxProduct(vector<string>& words) {
        int maxi=0;
        vector<ll> v;
        for(auto x:words){
            ll c=0;
            for(int i=0;i<x.size();i++){
                c=c|(1<<(x[i]-'a'));
            }
            v.push_back(c);
        }
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(!(v[i] & v[j])){
                    maxi=max(maxi,words[i].size()*words[j].size());
                }
            }
        }
        return maxi;
    }
};