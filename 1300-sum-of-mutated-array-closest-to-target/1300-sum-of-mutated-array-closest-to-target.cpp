class Solution {
public:
    int check(int m,vector<int> arr,int target){
        int c=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>m){
                c+=m;
            }else{
                c+=arr[i];
            }
        }
        return abs(c-target);
    }
    
    int findBestValue(vector<int>& arr, int target) {
        int l=0,h=1e5+2;
        while(l<h){
            int m=l+(h-l)/2;
            if(check(m,arr,target)>check(m+1,arr,target)){
                l=m+1;
            }else{
                h=m;
            }
            
            // cout<<l<<" "<<h<<endl;
        }
        return l;
    }
};