class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<arr.size();i++){
            pq.push({abs(x-arr[i]),i});
        }
        int c=0;
        vector<int> v;
        while(!pq.empty() && c<k){
            
            pair<int,int> p=pq.top();
            // cout<<p.second<<endl;
            pq.pop();
            v.push_back(arr[p.second]);
            c++;
        }
        sort(v.begin(),v.end());
        return v;
    }
};