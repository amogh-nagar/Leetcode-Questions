class Solution {
public:
    bool detectCapitalUse(string word) {
        int s=0,c=0;
        for(int i=0;i<word.length();i++){
            if(word[i]>='A' && word[i]<='Z'){
                c++;
            }else if(word[i]>='a' && word[i]<='z'){
                s++;
            }
        }
        int n=word.length();
        return (c==1 && word[0]>='A' && word[0]<='Z' && s==n-1) || (c==n && s==0) || (s==n && c==0);
    }
};