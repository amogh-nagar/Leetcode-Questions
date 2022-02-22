class Solution {
public:
    int titleToNumber(string columnTitle) {
        int c=0;
        for(int i=0;i<columnTitle.length();i++){
            c+=(pow(26,(columnTitle.length()-i-1))*(columnTitle[i]-'A'+1));
        }
        return c;
    }
};