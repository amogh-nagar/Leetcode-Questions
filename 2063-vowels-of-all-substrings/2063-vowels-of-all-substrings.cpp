class Solution {
public:
    typedef long long int ll;
    long long countVowels(string word) {
        ll s=0;
        for(int i=0;i<word.length();i++){
            if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'){
                s+=((ll)(word.length()-i)*i+(word.length()-i));
            }
        }
        return s;
    }
};