class Solution {
public:
     
    bool static comp(vector<int> a,vector<int> b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& is) {
        sort(is.begin(),is.end(),comp);
        pair<int,int> t{is[0][0],is[0][1]};
        int c=1;
        for(int i=1;i<is.size();i++){
            if(!(is[i][0]>=t.first && is[i][1]<=t.second)){
                c++;
                t.first=is[i][0];
                t.second=is[i][1];
            }
        }
        return c;
        
    }
};