class Solution {
public:
    int numberOfSteps(int num) {
        int c=0;
        while(num){
            if(num & 1)
                num--; 
            else
                num>>=1;
            c++;
        }
        return c;
    }
};