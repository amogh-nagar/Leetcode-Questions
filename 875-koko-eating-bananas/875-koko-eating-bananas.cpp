class Solution {
public:
    bool check(vector<int>& piles,int m,int h){
        int x=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%m==0)
                x+=(piles[i]/m);
            else
               x+=((piles[i]+m)/m);
        }
        return x<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,u=0;
        for(int i=0;i<piles.size();i++){
            u=max(u,piles[i]);
        }
        int ans=0;
        while(l<=u){
            int m=(l+u)/2;
            if(check(piles,m,h)){
                u=m-1;
                ans=m;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};