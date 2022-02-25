class Solution {
public:
    typedef long long ll;
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<double,ll> m;
        ll c=0;
        
        for(auto x:rectangles){
            c+=m[(double)x[0]/x[1]];
            m[(double)x[0]/x[1]]++;
        }
        return c;
    }
};