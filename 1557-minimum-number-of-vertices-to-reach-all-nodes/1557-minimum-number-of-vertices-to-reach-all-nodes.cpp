class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> graph(n,0);
        for(auto x:edges){
            graph[x[1]]++;
        }
        
        vector<int> res;
        for(int i=0;i<n;i++){
            if(graph[i]==0){
                res.push_back(i);
            }
        }
        return res;
    }
    
};