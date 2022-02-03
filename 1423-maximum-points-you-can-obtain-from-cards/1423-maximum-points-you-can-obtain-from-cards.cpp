class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int sum=0;
        for(int i=0;i<c.size() && i<k;i++){
            sum+=c[i];
        }
        if(k==c.size())
            return sum;
        
        int maxsum=sum;
        int i=k-1,j=c.size()-1;
        while(i>=0 && j>i){
            sum-=c[i--];
            sum+=c[j--];
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};