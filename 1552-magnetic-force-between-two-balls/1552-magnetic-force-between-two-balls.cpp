class Solution {
public:
    bool check(vector<int> pos, int m,int mid){
        int c=1,i=0,x=pos[0];
        // cout<<mid<<endl;
        while(i<pos.size()){
            if(pos[i]>=(x+mid)){
                c++;
                x=pos[i];
            }
            i++;
        }
        return c>=m;
    }
    
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l=1,ans=0,h=1e9;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(position,m,mid)){
                l=mid+1;
                ans=mid;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};