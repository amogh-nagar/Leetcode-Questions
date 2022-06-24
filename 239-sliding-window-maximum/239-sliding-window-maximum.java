class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        int i=0;
        
        while(k--){
            if(dq.empty() || !dq.empty() && dq.front().first<nums[i]){
             while(!dq.empty() && dq.front().first<nums[i])
                 dq.pop_front();
              dq.push_front({nums[i],i});
            }
            else{
                while(!dq.empty() && dq.back().first<nums[i])
                    dq.pop_back();
                
                dq.push_back({nums[i],i});
            }
            i++;
        }
        int j=1;
        vector<int> res;
        res.push_back(dq.front().first);
        for(;i<nums.size();i++,j++){
            if(!dq.empty() && dq.front().second<j){
                dq.pop_front();
            }
            
            if(!dq.empty() && dq.front().first<nums[i])
            {
                while(!dq.empty() && dq.front().first<nums[i])
                 dq.pop_front();
              dq.push_front({nums[i],i});
            }
            else{
                while(!dq.empty() && dq.back().first<nums[i])
                    dq.pop_back();
                
                dq.push_back({nums[i],i});
            }
            res.push_back(dq.front().first);
        }
        return res;
    }
};