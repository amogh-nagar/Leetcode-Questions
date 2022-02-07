class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int> pref(n,0);
        pref[0]=arr[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]^arr[i];
        }
        int c=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j;k<n;k++){
                    int x=(i!=0 ? pref[j-1]^pref[i-1]:pref[j-1]);
                    int y=pref[k]^pref[j-1];
                    if(x==y){
                        c++;
                    }
                }
            }
        }
        return c;
    }
};