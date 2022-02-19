class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto x:nums){
            if(x & 1){
                pq.push(x*2);
            }else{
                pq.push(x);
            }
            
        }
        int mini=INT_MAX,maxi=INT_MIN;
        for(auto x:nums){
            if(x & 1){
                x*=2;
            }
            mini=min(mini,x);
            maxi=max(maxi,x);
        }
        int diff=pq.top()-mini;
        while(pq.top()%2==0){
            diff=min(diff,pq.top()-mini);
            int t=pq.top();
            pq.pop();
            mini=min(mini,t/2);
            pq.push(t/2);
        }
        diff=min(diff,pq.top()-mini);
            
        
        return diff;
        
    }
};