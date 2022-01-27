class Solution {
public:
    int minFlips(int a, int b, int c) {
        int s=0;
        for(int j=31;j>=0;j--){
            if(c & (1<<j)){
                if(!(a & (1<<j)) && !(b & (1<<j))){
                    s++;
                }
            }else{
                if(a & (1<<j)){
                    s++;
                }
                if(b & (1<<j)){
                    s++;
                }
            }
        }
        return s;
    }
};