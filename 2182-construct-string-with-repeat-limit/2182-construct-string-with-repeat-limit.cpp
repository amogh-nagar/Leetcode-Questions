class Solution {
public:
    string repeatLimitedString(string s, int r) {
        map<int,int> m;
        for(auto x:s){
            m[x]++;
        }
        
        priority_queue<pair<char,int>> pq;
        for(auto x:m){
            pq.push({x.first,x.second});
        }
        string res;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            
            int l=min(x.second,r);
            x.second-=r;
            res+=(string(l,x.first));
            
            if(x.second>0){
                if(pq.empty()){
                    return res;
                }
                auto y=pq.top();
                pq.pop();
                
                res+=(string(1,y.first));
                y.second-=1;
                if(y.second>0){
                    pq.push({y.first,y.second});
                }
               pq.push({x.first,x.second});
            }

            
            
        }
        return res;
    }
};