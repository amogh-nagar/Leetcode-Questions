class Solution {
public:
    static bool comp(pair<int,int> a,pair<int,int> b){
        return a.first>b.first;
    }
    
    
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
       pair<int,int> p[aliceValues.size()];
       for(int i=0;i<aliceValues.size();i++){
            p[i].first=(aliceValues[i]+bobValues[i]);
            p[i].second=i;
       }
        sort(p,p+aliceValues.size(),comp);
        int x=0,y=0;
        for(int i=0;i<aliceValues.size();i++){
            if(i%2==0){
                x+=aliceValues[p[i].second];
            }else{
                y+=bobValues[p[i].second];
            }
        }
        return x==y?0:(x>y)?1:-1;
    }
};