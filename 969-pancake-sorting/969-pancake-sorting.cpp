class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> v;
        
        for(int i=arr.size();i>=1;i--){
            int j=0;
            for(j=0;j<arr.size();j++){
                if(arr[j]==i){
                    break;
                }
            }
            if(j==i-1){
                continue;
            }
            int x=0;
            if(j!=0){
                x=(j+1);
                reverse(arr.begin(),arr.begin()+j+1);
                v.push_back(x);
                x=0;
            }
            x+=(i);
            reverse(arr.begin(),arr.begin()+i);
            v.push_back(x);
        }
        return v;
    }
};