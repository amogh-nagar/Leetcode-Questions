class Solution {
public:
    typedef long long int ll;
    unsigned long long int mo=1e9+7;
    
    int minimumLines(vector<vector<int>>& sp) {
        sort(sp.begin(),sp.end());
        if(sp.size()==1){
            return 0;
        }
        ll c=0;
        long double m=(long double)(sp[1][1]-sp[0][1])/(sp[1][0]-sp[0][0]);c++;
        for(int i=2;i<sp.size();i++){
               long double t=(long double)(sp[i][1]-sp[i-1][1])/(sp[i][0]-sp[i-1][0]);
               if(m!=t){
                c++;
                m=t;  
               } 
        }
    return c;
    }
    
};
