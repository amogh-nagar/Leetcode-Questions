class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       int n=heights.size(),m=heights[0].size(); 
       vector<int> dr{1,-1,0,0};
        vector<int> dc{0,0,-1,1};
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto p=pq.top();pq.pop();
            int x=p.second.first,y=p.second.second;
            int eff=p.first;
            if(x==n-1 && y==m-1){
                return eff;
            }
            if(x<0 || y<0 || x>=n || y>=m || heights[x][y]==0){
                continue;
            }
            for(int i=0;i<4;i++){
                int nx=x+dr[i],ny=y+dc[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m){
                   continue;
                }
                int neff=max(eff,abs(heights[nx][ny]-heights[x][y]));
                pq.push({neff,{nx,ny}});
            }
            heights[x][y]=0;
        }
        return 0;
    }
};