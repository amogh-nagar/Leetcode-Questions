class Trie{
    public:
    char c;
    bool isterminal;
    unordered_map<char,Trie*> child;
    Trie(char x){
        this->isterminal=false;
        this->c=x;
        
    }
};


class WordDictionary {
public:
    Trie *tnode;
    void insertnode(string x){
        Trie *t=tnode;
        for(int i=0;i<x.length();i++){
            if(t->child.count(x[i])==0){
                t->child.insert({x[i],new Trie(x[i])});
                
            }
            
            t=t->child[x[i]];
        }
        t->isterminal=true;
    }
    bool searchnode(Trie *t,string x,int i){
        char c=x[i];
        // cout<<c<<endl;
        return t->child.count(c)!=0;
    }
    
    
    WordDictionary() {
        tnode = new Trie('0');
    }
    
    void addWord(string word) {
        insertnode(word);
    }
    
    bool solve(string word,Trie *t) {
        
        for(int i=0;i<word.length();i++){
            if(word[i]=='.'){
                int l=0;
                for(auto c='a';c<='z';c++){
                    // cout<<x.first<<" ";
                    if(t->child.count(c)!=0 && solve(word.substr(i+1),t->child[c])){
                      return true;
                    }
                }
                cout<<endl;
                if(!l){
                    return false;
                }
            }else{
                if(searchnode(t,word,i)){
                    t=t->child[word[i]];
                }else{
                    return false;
                }
                
            }
        }
        return t->isterminal;
    }
                       
    bool search(string word){
        Trie *t=tnode;
        return solve(word,t);
    }                   
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */