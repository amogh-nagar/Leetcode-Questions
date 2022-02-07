class Solution {
public:
    class Comp{
        public: bool operator()(pair<int,int> a,pair<int,int> b){
            if(a.second<b.second){
                return true;
            }
            if(a.second==b.second){
                if(a.first<b.first){
                    return true;
                }else{
                    return false;
                }
            }
            return false;
        }
    };
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> t(arr.begin(),arr.end());
        sort(t.begin(),t.end());
        int med=t[(arr.size()-1)/2];
        priority_queue<pair<int,int>,vector<pair<int,int>>,Comp> pq;
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],abs(arr[i]-med)});
        }
        vector<int> res;
        while(!pq.empty() && k--){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};