class Solution {
public:
    int numberOfSteps(int num) {
        int c=0;
        while(num){
            if(num & 1)
                c++; 
            
            num>>=1;
            if(num!=0)
            c++;
        }
        return c;
    }
};