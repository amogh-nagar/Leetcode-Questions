class Solution {
public:
    int count=0;
    void solve(vector<bool>& visited,int i,int n){
        if(i==n){
            count++;
            return;
        }
        for(int x=1;x<=n;x++){
            if(!visited[x] && (x%(i+1)==0||(i+1)%x==0)){
                visited[x]=true;
                solve(visited,i+1,n);
                visited[x]=false;
            }
        }
    }
    
    int countArrangement(int n) {
        vector<bool> visited(n,false);
        solve(visited,0,n);
        return count;
    }
};