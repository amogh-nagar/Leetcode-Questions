class Solution {
public:
    typedef long long int ll;
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<ll> s;
        ll t=0;
        for(auto x:nums){
            ll c=0;
            for(int i=x.length()-1;i>=0;i--){
               c+=((x[i]-'0')*(pow(2,x.length()-i-1)));  
            }
            s.insert(c);
        }
        while(s.find(t)!=s.end()){
            t++;
        }
        
        string r;
        for(int i=0;i<nums.size();i++){
            if(1<<i & t){
                r+='1';            
            }else{
                r+='0';
            }
        }
        reverse(r.begin(),r.end());
        return r;
    }
};