class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=points.size(),e=0,c=0;
        vector<int> vis(n,0);
        pq.push({0,0});
        while(e<n){
            auto x=pq.top();
            pq.pop();
            if(vis[x.second]){
                continue;
            }
            c+=x.first;
            e++;
            vis[x.second]=1;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                int t=abs(points[i][0]-points[x.second][0])+abs(points[i][1]-points[x.second][1]);
                pq.push({t,i});
                }    
            }
        }
        return c;
    }
};