class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> v;
        for(int i=0;i<trips.size();i++){
            v.push_back({trips[i][1],trips[i][0]});
            v.push_back({trips[i][2],-trips[i][0]});
        }
        int x=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            x+=v[i].second;
            if(x>capacity)
                return false;
        }
        return true;
    }
};