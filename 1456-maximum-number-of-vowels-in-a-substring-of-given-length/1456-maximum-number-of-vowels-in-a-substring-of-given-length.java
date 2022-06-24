class Solution {
    boolean isvowel(char x){
        return x=='a'||x=='e'||x=='i'||x=='o'||x=='u';
    }
    public int maxVowels(String s, int k) {
        
        int c=0,maxi=0;
        
        for(int i=0,j=0;j<s.length();j++){
            if(j-i+1==k+1 && isvowel(s.charAt(i)))c--;
            if(isvowel(s.charAt(j)))c++;
            maxi=Math.max(maxi,c);
            if(j>k-1){
                i++;
            }
        }
        return maxi;
        
    }
}