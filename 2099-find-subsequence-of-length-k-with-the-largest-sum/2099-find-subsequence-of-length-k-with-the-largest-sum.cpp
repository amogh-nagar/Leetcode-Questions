class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        vector<int> vis(nums.size(),0);
        while(!pq.empty() && k--){
            vis[pq.top().second]=1;
            pq.pop();
        }
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(vis[i]){
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};