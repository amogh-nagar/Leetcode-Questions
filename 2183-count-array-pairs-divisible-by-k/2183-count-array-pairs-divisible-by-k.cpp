class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        
        long long res=0;
        unordered_map<long long,long long> m;
        for(auto i:nums){
            m[__gcd(i,k)]++;
        }
        
        for(auto x:m){
            for(auto y:m){
                if(x.first<=y.first && (x.first*y.first)%k==0){
                    auto c1=x.second,c2=y.second;
                    res+=(x.first==y.first?(c1*(c1-1)/2):c1*c2);
                }
            }
        }
        return res;
        
        
    }
};