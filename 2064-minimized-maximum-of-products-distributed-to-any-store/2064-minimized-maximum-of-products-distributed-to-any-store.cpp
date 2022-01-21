class Solution {
public:
    bool check(int m,vector<int> v,int n){
        int c=0;
        for(int i=0;i<v.size();i++){
            c+=((v[i]/m)+(v[i]%m!=0));
        }
        return c<=n;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1,h=0;
        for(int i=0;i<quantities.size();i++){
            h=max(h,quantities[i]);
        }
        int ans=0;
        while(l<=h){
            int m=(l+h)/2;
            if(check(m,quantities,n)){
                ans=m;
                h=m-1;
            }else{
                l=m+1;
            }
            // cout<<m<<endl;
        }
        return ans;
    }
};