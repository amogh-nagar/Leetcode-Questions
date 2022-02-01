class Solution {
public:
    static bool comp(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }
    
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        for(int i=0;i<times.size();i++){
            times[i].push_back(i);
        }
        sort(times.begin(),times.end(),comp);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        priority_queue<int,vector<int>,greater<int>> chairs;
        for(int i=0;i<times.size();i++){
            chairs.push(i);
        }
        
        
        for(int i=0;i<times.size();i++){
                while(!pq.empty() && pq.top().first<=times[i][0]){
                    chairs.push(pq.top().second);
                    pq.pop();
                }
                if(times[i][2]==targetFriend){
                    return chairs.top();
                }
                pq.push({times[i][1],chairs.top()});chairs.pop();
            
        }
        return 0;
    }
};