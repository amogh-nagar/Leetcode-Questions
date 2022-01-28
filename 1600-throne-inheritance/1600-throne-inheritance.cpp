class Node{
    public:
    string name;
    int is_live;
    vector<Node*> child;
    Node(string x){
        this->name=x;
        this->is_live=true;
    }
};

class ThroneInheritance {
public:
    Node*tnode;
    unordered_map<string,Node*> m;
    ThroneInheritance(string kingName) {
        tnode=new Node(kingName);
        m[kingName]=tnode;
    }
    void birth(string parentName, string childName) {
     
        auto x=new Node(childName);
        m[parentName]->child.push_back(x);
        m[childName]=x;
    }
    
    void death(string name) {
        m[name]->is_live=false;
    }
    
    vector<string> getInheritanceOrder() {
        Node*t=tnode;
        vector<string> ans;
        dfs(ans,t);
        return ans;
    }
    void dfs(vector<string>&ans,Node*t){
        if(t->is_live){
            ans.push_back(t->name);
        }
        
        for(auto n:t->child){
            dfs(ans,n);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */