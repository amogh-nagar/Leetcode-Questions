class Trie{
    
   public: Trie* child[2];
    
    Trie(){
        this->child[0]=NULL;
        this->child[1]=NULL;
    }
};


class Solution {

    Trie *tnode;
    
    
    public:
    
    void insert(int x){
        Trie *t=tnode;
        bitset<32> bt(x);
        for(int i=31;i>=0;i--){
            if(!t->child[bt[i]]){
                t->child[bt[i]]=new Trie();
                
            }
            t=t->child[bt[i]];
        }
    }
    
    int maxxor(int x){
       Trie *t=tnode;
       bitset<32> bt(x);
    int ans=0;
        for(int j=31;j>=0;j--){
        if(t->child[!bt[j]]){
            ans|=(1<<j);
            t=t->child[!bt[j]];
        }else{
            t=t->child[bt[j]];
        }
    }
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        tnode=new Trie();  
        
        for(auto x:nums){
              insert(x);
          }
        
        int ans=INT_MIN;
        for(auto x:nums){
            ans=max(ans,maxxor(x));
        }
        return ans;
    }
};