class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int nn) {
        if(flowerbed.size()==1 && flowerbed[0]==0 && nn==1){
            return 1;
        }
        int c=0,s=0,n=flowerbed.size();
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
              if(i>0 && flowerbed[i-1]==0 && i<n-1 && flowerbed[i+1]==0 && i-1!=c ){
                  c=i;
                  s++;
              }else if(i==0 && i+1<n && flowerbed[i+1]==0){
                  c=i;
                  s++;
              }else if(i==n-1 && i>0 && flowerbed[i-1]==0 && i-1!=c){
                  c=i;
                  s++;
              }
            }
        }
        return s>=nn;
    }
    
};