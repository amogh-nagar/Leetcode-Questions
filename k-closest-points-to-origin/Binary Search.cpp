class Solution {
public:
    bool check(vector<vector<int>>& points,int m, int k){
        int c=0;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            if(x*x+y*y<=m){
                c++;
            }
        }
        return c<=k;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int l=0,h=0;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            h=max(h,x*x+y*y);
        }
        int ans=0;
        while(l<=h){
            int m=(l+h)/2;
            

            if(check(points,m,k)){
                l=m+1;
                ans=m;
            }else{
                h=m-1;
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            if(x*x+y*y<=ans){
                res.push_back({x,y});
            }
        }
        return res;
    }
};