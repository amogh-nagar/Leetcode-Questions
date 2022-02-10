class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& flist, vector<vector<int>>& slist) {
        vector<vector<int>> res;
        for(int i=0;i<flist.size();i++){
            vector<int> t=flist[i];
            for(int j=0;j<slist.size();j++){
                if(slist[j][0]>=t[0] && slist[j][0]<=t[1]){
                    res.push_back({slist[j][0],min(t[1],slist[j][1])});
                }
                else if(slist[j][1]>=t[0] && slist[j][1]<=t[1]){
                    res.push_back({t[0],min(t[1],slist[j][1])});
                }else if(slist[j][0]<=t[0] && slist[j][1]>=t[0]){
                    res.push_back({t[0],min(t[1],slist[j][1])});
                    
                }else if(slist[j][0]<=t[1] && slist[j][1]>=t[1]){
                    
                    res.push_back({slist[j][0],min(t[1],slist[j][1])});
                }
            }
        }
        return res;
    }
};