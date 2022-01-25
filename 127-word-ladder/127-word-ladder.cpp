class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int l=0;
        unordered_set<string> s;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==endWord){
                l=1;
                
            }
            s.insert(wordList[i]);
        }
        if(!l){
            return 0;
        }
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> vis;
        vis.insert(beginWord);
        while(!q.empty()){
            int f=0;
            pair<string,int> cw=q.front();
            q.pop();
            if(cw.first==endWord){
                return cw.second;
            }
            
            for(int i=0;i<cw.first.size();i++){
                string tt=cw.first;
                // cout<<"i "<<tt<<" ";
                for(int j=0;j<26;j++){
                    tt[i]=j+'a';
                    
                if(tt!=cw.first && vis.find(tt)==vis.end() && s.find(tt)!=s.end()){
                    // cout<<"pp"<<" ";
                        q.push({tt,cw.second+1});
                        vis.insert(tt);
                    
                }
            
                // cout<<tt<<endl;
                }
                // cout<<cw.first<<" "<<cw.second<<endl;
            }
        }
        return 0;
    }
};