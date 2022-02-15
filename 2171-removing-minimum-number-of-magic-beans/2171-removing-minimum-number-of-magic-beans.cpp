class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long c=LLONG_MAX,n=beans.size();
        sort(beans.begin(),beans.end());
        vector<long long> pref(n,0);
        pref[0]=beans[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+beans[i];
        }
        
        for(int i=0;i<n;i++){
            if(i==0){
                c=min(c,pref[n-1]-pref[0]-(n-1)*beans[i]);
            }else if(i==n-1){
                c=min(c,pref[n-2]);
            }else{
                c=min(c,pref[i-1]+pref[n-1]-pref[i]-(n-i-1)*beans[i]);
            }
        }
        
        return c;
    }
};