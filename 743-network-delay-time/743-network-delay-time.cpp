class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> v(n+1);
        for(int i=0;i<times.size();i++){
            v[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> time(n+1,INT_MAX);
        time[k]=0;
        queue<pair<int,int>> q;
        q.push({0,k});
        while(!q.empty()){
            pair<int,int> x=q.front();
            q.pop();
            
            for(auto it:v[x.second]){
                if(time[it.first]>x.first+it.second){
                    time[it.first]=x.first+it.second;
                    q.push({time[it.first],it.first});
                }
            
            }        
            
        }
        int x=*max_element(time.begin()+1,time.end());
        if(x==INT_MAX)
            return -1;
        return x;
        
    }
};