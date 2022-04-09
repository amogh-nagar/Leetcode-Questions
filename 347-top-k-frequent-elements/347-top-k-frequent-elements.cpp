class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto x:nums){
            m[x]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto x:m){
            pq.push({x.second,x.first});
            
        }
        vector<int> v;
        while(k--){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};