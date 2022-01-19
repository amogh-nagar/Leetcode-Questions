class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size()==0){
            return m*n;
        }
        int c=1;
        pair<int,int> p{ops[0][0],ops[0][1]};
        for(int i=1;i<ops.size();i++){
            p={min(ops[i][0],p.first),min(ops[i][1],p.second)};
            c++;
            
        }
        return (p.first*p.second); 
    }
};