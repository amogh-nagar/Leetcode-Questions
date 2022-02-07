class Solution {
public:
    bool solve(vector<vector<int>> v,int mid,int c){
        for(int i=mid-1;i<v.size();i++){
            for(int j=mid-1;j<v[0].size();j++){
                int x=v[i][j];
                if(i-mid>=0){
                    x-=v[i-mid][j];
                }
                       if(j-mid>=0){
                           x-=v[i][j-mid];
                       }
                       if(i-mid>=0 && j-mid>=0){
                           x+=v[i-mid][j-mid];
                       }
                       if(x<=c){
                    return true;
                }
            }
        }
        return false;
    }
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    v[i][j]=mat[i][j];
                }else if(i==0){
                    v[i][j]=v[i][j-1]+mat[i][j];
                }else if(j==0){
                    v[i][j]=v[i-1][j]+mat[i][j];
                }else{
                    v[i][j]=v[i-1][j]+v[i][j-1]-v[i-1][j-1]+mat[i][j];
                }
            }
        }
        
        int l=0,ans=0,h=min(n,m);
        while(l<=h){
            int mid=(l+h)/2;
            
            if(solve(v,mid,threshold)){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};