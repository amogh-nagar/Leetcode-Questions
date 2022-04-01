class Solution {
public:
    int dp[1001][1001];
    int solve(int copy,int l,int n){
        // cout<<copy<<" "<<l<<endl;
        if(l==n){
            return 0;
        }
        if(l>n){
            return INT_MAX;
        }
        if(dp[l][copy]!=-1){
            return dp[l][copy];
        }
        
        int c1=solve(copy,l+copy,n);
        if(c1!=INT_MAX){
            c1++;
        }
        int c2=l!=1?solve(l,l+l,n):INT_MAX;
        if(c2!=INT_MAX){
            c2+=2;
        }
        // cout<<": "<<c1<<" "<<c2<<endl; 
        return dp[l][copy]=min(c1,c2);
        
    }
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        return 1+solve(1,1,n);
    }
};