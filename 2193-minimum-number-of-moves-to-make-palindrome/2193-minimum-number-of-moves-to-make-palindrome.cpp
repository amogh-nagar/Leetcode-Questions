class Solution {
public: 
    int minMovesToMakePalindrome(string s) {
        int c=0;
        int i=0,j=s.length()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;j--;continue;
            }
            int k=0,l=0;
            for(k=i+1;k<j;k++){
               if(s[k]==s[j]){
                   break;
               }   
            }
            if(k==j){
                swap(s[j],s[j-1]);
                c++;
                continue;
            }
            for(l=k;l>i;l--){
                c++;
                swap(s[l],s[l-1]);
            }
            i++;
            j--;
        }
        return c;
    }
};