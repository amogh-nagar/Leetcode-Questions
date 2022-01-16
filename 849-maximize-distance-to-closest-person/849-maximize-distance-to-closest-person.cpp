class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int c=0,p=-1,x=0;
         
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1){
                p=i;
                break;
            }
        }
        x=max(x,p);
        int l=0;
        int n=seats.size()-1;
        for(int i=seats.size()-1;i>=0;i--){
            if(seats[i]==1){
               x=max(x,n-i);
        l=i;        
        break;
            }
        }
        
        for(int i=p+1;i<l;i++){
            if(seats[i]==1){
                c=0;
            }else{
                c++;
                x=max(x,(c+1)/2);
            }
        }
        return x;
    }
};