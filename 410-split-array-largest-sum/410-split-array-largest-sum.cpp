class Solution {
public:
    bool check(int m,vector<int>& nums,int mid){
        int c=0,s=0;
        for(auto x:nums){
            if(x>mid){
                return false;
            }
            s+=x;
            if(s>mid){
                c++;
                s=x;
            }
        }
        if(s>mid){
            c++;
        }
        c++;
        return c<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int l=0,h=0;
        for(auto x:nums){
            h+=x;
        }
        
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            cout<<mid<<endl;
            if(check(m,nums,mid)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};