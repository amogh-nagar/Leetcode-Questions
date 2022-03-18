class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> pref(n,INT_MAX),suff(n,INT_MAX);
        int j=0,s=0;
        for(int i=0;i<n;i++){
            s+=arr[i];
            while(j<=i && s>target){
                s-=arr[j];
                j++;
            }
            if(s==target){
                if(i==0){
                    pref[i]=(i-j+1);
                    continue;
                }
                pref[i]=min(pref[i-1],i-j+1);
            }else{
                if(i!=0)
                pref[i]=pref[i-1];
            }
        }
        j=n-1,s=0;
        for(int i=n-2;i>=0;i--){
            s+=arr[i+1];
            while(j>i && s>target){
                s-=arr[j];
                j--;
            }
            if(s==target){
                suff[i]=min(suff[i+1],j-i);
            }else{
                suff[i]=suff[i+1];
            }
        }
        int minl=INT_MAX;
        for(int i=0;i<n;i++){
            if(pref[i]!=INT_MAX && suff[i]!=INT_MAX)
             minl=min(minl,pref[i]+suff[i]);
        }
        return minl==INT_MAX?-1:minl;
    }
};