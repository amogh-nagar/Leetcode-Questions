class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int x=0;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]<arr[i+1]){
                if(x==2){
                    return false;
                }  
                
                x=1;
            }else if(arr[i]>arr[i+1]){
                if(x==0){
                    return false;
                }
                x=2;
            }else if(arr[i]==arr[i+1]){
                return false;
            }
        }
        return x==2;
    }
};