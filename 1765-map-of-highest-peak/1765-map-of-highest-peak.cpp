class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,pair<int,int>>> q;
        int n=isWater.size(),m=isWater[0].size();
        
        vector<vector<int>> v(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    v[i][j]=0;
                    q.push({0,{i,j}});
                }
            }
            
        }
        vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int x=q.front().second.first;
            int y=q.front().second.second;
            int d=q.front().first;
            q.pop();
            for(int i=0;i<4;i++){
                int x1=x+dir[i][0];
                int y1=y+dir[i][1];
                if(x1>=0 && y1>=0 && x1<n && y1<m && v[x1][y1]>1+v[x][y] ){
                    v[x1][y1]=d+1;
                    q.push({d+1,{x1,y1}});
                }
            }
        }
        return v;
    }
};