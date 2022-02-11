class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m1(26,0),m2(26,0);
        for(int i=0;i<s1.length();i++){
            m1[s1[i]-'a']++;
        }
        int j=0;
        for(int i=0;i<s2.length();i++){
            m2[s2[i]-'a']++;
            
             while(j<=i && m2[s2[i]-'a']>m1[s2[i]-'a']){
                
                m2[s2[j]-'a']--;
                j++;   
                   
               }
                
            
            if(m1==m2){
                return true;
            }
        }
         if(m1==m2){
                return true;
            }
        return false;
    }
};