class Solution {
public:
    class Compare{
      public: bool operator()(pair<int,int> a,pair<int,int> b){
          return a.second<b.second;
      }  
    };
    
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        for(auto it:m){
            pq.push({it.first,it.second});
        }
        int x=arr.size(),c=0;
        while(x>(arr.size()/2)){
            // cout<<pq.top().first<<endl;
            x-=pq.top().second;
            pq.pop();
            c++;
        }
        return c;
    }
};