class Solution {
public:
    bool search(vector<int>& a, int target) {
        if(a.size()==1){
            return a[0]==target;
        }
        
        int l=0,h=a.size()-1;
        while(l<=h){
            
            while(l<h && a[l] == a[l+1])
                l++;
            while(l<h && a[h] == a[h-1])
                h--;
            int m=l+(h-l)/2;
            if(a[m]==target){
                return true;
            }
            if(a[l]<=a[m]){
                if(target>=a[l] && target<=a[m]) h=m-1;
                else l=m+1;
            }else if(a[m]<=a[h]){
                if(target>=a[m] && target<=a[h]) l=m+1;
                else h=m-1;
            }
        }
        return false;
    }
};