class Solution {
public:
    
    bool solve(string s1,string s2){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        for(int i=0;i<s1.length();i++){
           if(s2[i]<s1[i]){
               return false;
           }
        }
        return true;
    }
    
    bool checkIfCanBreak(string s1, string s2) {
        return solve(s1,s2)||solve(s2,s1);
    }
};