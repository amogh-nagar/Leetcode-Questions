class Solution {
public:
 unsigned const int mo=1e9 + 7;
    
    int threeSumMulti(vector<int>& arr, int target) {
        map<int,long long int> m;
        for(auto x:arr){
            m[x]++;
        }
        long long int c=0;
        for(auto x:m){
             for(auto y:m){
                 if(x.first>y.first){
                     continue;
                 }
                 int t=target-x.first-y.first;
                 if(x.first==y.first && y.first==t){
                     c+=((x.second)*(x.second-1)*(x.second-2))/6;
                 }
                 else if(x.first==y.first && y.first!=t){
                     c+=(((x.second)*(x.second-1))/2)*m[t];
                 }else if(y.first<t){
                     c+=(x.second*y.second*m[t]);
                 }
        c%=mo;
             }
            
        }
        return c;
    }
};