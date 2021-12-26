class Solution {
public:
    
    class Compare{
        public: bool operator()(pair<int,int> a,pair<int,int> b){
            return a.second>b.second;
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int> v;
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        for(int i=0;i<points.size();i++){
            int x=points[i][0],y=points[i][1];
            pq.push({i,x*x+y*y});
        }
        vector<vector<int>> res;
        while(k--){
            res.push_back({points[pq.top().first][0],points[pq.top().first][1]});
            pq.pop();
        }
        return res;
    }
};