class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int maxl=0,uplen=0,downlen=0;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1] || downlen && arr[i]<arr[i+1]){
                uplen=downlen=0;
            }
            uplen+=(arr[i]<arr[i+1]);
            downlen+=(arr[i]>arr[i+1]);
            if(uplen && downlen){
                maxl=max(maxl,uplen+downlen+1);
            }
        }
        return maxl;
    }
};