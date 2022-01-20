class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0,m=INT_MAX,pi=0,h=0;
        for(int i=0;i<arr.size();i++){
            if(m>(abs(arr[i]-x))){
                m=abs(arr[i]-x);
                pi=i;
            }
        }
        cout<<pi;
        vector<int> v;
        v.push_back(arr[pi]);
        l=pi-1;
        h=pi+1;
        int c=1;
        while((l>=0 || h<arr.size()) && c<k){
            int y=INT_MAX,p=INT_MAX;
            if(l>=0){
                p=abs(arr[l]-x);
               
            }
            if(h<arr.size()){
                y=abs(arr[h]-x);
                
            }
            if(p>y){
                
                v.push_back(arr[h]);
                h++;
            }else{
                v.push_back(arr[l]);
                l--;
            }
            c++;
        }
        sort(v.begin(),v.end());
        return v;
        
    }
};