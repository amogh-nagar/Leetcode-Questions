class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int c1=0,c2=0,c3=0,c4=0;
        int num1=tops[0],num2=bottoms[0],n=tops.size();
        for(int i=0;i<n;i++){
            if(c1!=INT_MAX){
                if(tops[i]==num1){
                    
                }else if(bottoms[i]==num1){
                    c1++;
                }else{
                    c1=INT_MAX;
                }
            }
            if(c2!=INT_MAX){
                if(bottoms[i]==num1){
                    
                }else if(tops[i]==num1){
                    c2++;
                }else{
                    c2=INT_MAX;
                }
            }
            if(c3!=INT_MAX){
                if(tops[i]==num2){
                    
                }else if(bottoms[i]==num2){
                    c3++;
                }else{
                    c3=INT_MAX;
                }
            }
            if(c4!=INT_MAX){
                if(bottoms[i]==num2){
                    
                }else if(tops[i]==num2){
                    c4++;
                }else{
                    c4=INT_MAX;
                }
            }
            
            
        }
        
        int ans=min(c1,min(c2,min(c3,c4)));
        return ans==INT_MAX?-1:ans;
    }
};