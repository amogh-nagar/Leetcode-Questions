class TopVotedCandidate {
public:
    vector<int> lds,tms;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int,int> m;
        tms=times;
        int l=0;
        for(int i=0;i<persons.size();i++){
            m[persons[i]]++;
            if(m[persons[i]]>=m[l]){
                l=persons[i];
            }
            lds.push_back(l);
        }
    }
    
    int q(int t) {
        int idx=upper_bound(tms.begin(),tms.end(),t)-tms.begin();
        return lds[idx-1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */