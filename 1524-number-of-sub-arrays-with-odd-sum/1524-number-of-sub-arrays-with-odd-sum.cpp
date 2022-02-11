class Solution {
public:
    long long mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        map<int,int> m;
        int ans=0,sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2!=0){
                ans++;
            }
            if(sum%2){
                ans+=m[0];
                
                ans%=mod;
                m[1]++;
            }else{
                ans+=m[1];
                ans%=mod;
                m[0]++;
            }
        }
        return ans%mod;
    }
};