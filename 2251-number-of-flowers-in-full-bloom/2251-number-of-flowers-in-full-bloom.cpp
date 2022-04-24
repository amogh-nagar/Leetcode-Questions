class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int n=persons.size();
        vector<int> pref(n,0),ranges(persons.begin(),persons.end());
        sort(persons.begin(),persons.end());
        for(int i=0;i<flowers.size();i++){
            int x=flowers[i][0],y=flowers[i][1];
            int l=lower_bound(persons.begin(),persons.end(),x)-persons.begin();
            int h=upper_bound(persons.begin(),persons.end(),y)-persons.begin();
            if(l<n)
            pref[l]++;
            if(h<n)
            pref[h]--;
        }
        
        for(int i=1;i<n;i++){
            pref[i]+=pref[i-1];
        }
        vector<int> v(n,0);
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[persons[i]]=pref[i];
            
        }
        for(int i=0;i<n;i++){
            v[i]=m[ranges[i]];
        }
        return v;
    }
};