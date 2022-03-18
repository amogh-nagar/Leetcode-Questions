class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> pref(n,INT_MAX);
        int j=0,s=0,minl=INT_MAX;
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
                if(j!=0 && pref[j-1]!=INT_MAX)
                minl=min(minl,i-j+1+pref[j-1]);
            }else{
                if(i!=0)
                pref[i]=pref[i-1];
            }
        }
        return minl==INT_MAX?-1:minl;
    }
};