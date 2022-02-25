class Solution {
public:
    typedef long long ll;
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<double,ll> m;
        ll c=0;
        
        for(auto x:rectangles){
            m[(double)x[0]/x[1]]++;
        }
        
        for(auto x:m){
          auto y=x.second;
          c+=(y*(y-1)/2);    
        }
        
        return c;
    }
};