class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int c=0,l=0,index=0;
        for(int i=0;i<gas.size();i++){
            c+=(gas[i]-cost[i]);
            
            if(c<l){
                index=i+1;
                l=c;  
            }
        }
        return c<0?-1:index%gas.size();
    }
};