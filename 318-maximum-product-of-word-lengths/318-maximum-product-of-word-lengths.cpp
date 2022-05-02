class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<unordered_set<char>> v(words.size()); 
        for(int i=0;i<words.size();i++){
             for(auto x:words[i]){
                 v[i].insert(x);
             }
         }
        int maxi=0;
        for(int i=0;i<words.size();i++){
             for(int j=i+1;j<words.size();j++){
                int f=0;
                 for(char x='a';x<='z';x++){
                   if(v[i].find(x)!=v[i].end() && v[j].find(x)!=v[j].end()){
                       f=1;
                       break;
                   } 
                }
                 if(!f){
                maxi=max(maxi,(int)words[i].length()*(int)words[j].length());
                 }
             }
         }
        return maxi;
    }
};