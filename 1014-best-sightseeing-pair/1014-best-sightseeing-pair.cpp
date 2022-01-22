class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int c=INT_MIN,prev=values[0];
        for(int i=1;i<values.size();i++){
            c=max(c,prev+values[i]-i);
            prev=max(prev,values[i]+i);
        }
        
        return c;
    }
};