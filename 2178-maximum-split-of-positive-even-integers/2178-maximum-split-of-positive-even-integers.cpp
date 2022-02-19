class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum & 1){
            return {};
        }
        vector<long long> res;
        long long int i=2,currsum=0;
        while(currsum+i<=finalSum){
            res.push_back(i);
            
            currsum+=i;
            i+=2;
        }
        res[res.size()-1]+=(finalSum-currsum);
        return res;
    }
};