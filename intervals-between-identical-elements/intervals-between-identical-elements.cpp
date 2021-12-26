class Solution {
public:
    typedef long long ll;
    vector<long long> getDistances(vector<int>& arr) {
        int n=arr.size();
        vector<ll> v(n,0);
        unordered_map<int,pair<ll,int>> prefix,suffix;
        
        for(int i=0;i<arr.size();i++){
            pair<ll,int> x=prefix[arr[i]];
            ll s=x.first;
            int c=x.second;
            v[i]+=abs((long long)c*i-s);
            prefix[arr[i]].first+=i;
            prefix[arr[i]].second+=1;
        }
        for(int i=arr.size()-1;i>=0;i--){
            pair<ll,int> x=suffix[arr[i]];
            ll s=x.first;
            int c=x.second;
            v[i]+=abs(s-(long long)c*i);
            suffix[arr[i]].first+=i;
            suffix[arr[i]].second+=1;
        }
        return v;
    }
};