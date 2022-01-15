class LRUCache {
public:
    class Node{
     public:   int key,value;
        Node(int k,int v){
            this->key=k;
            this->value=v;
        }
    };
    int x=0,c=0;
    map<int,list<Node>::iterator> m;
    list<Node> l;
    LRUCache(int capacity) {
        x=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        
        auto x=m[key];
        l.push_front(*x);
        l.erase(x);
        
        m[key]=l.begin();
       
        return l.begin()->value;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            auto it=m[key];
            // it->value=value;
            Node n(key,value);
            l.push_front(n);
            l.erase(it);
            m[key]=l.begin();
        }
        else{
        if(l.size()==x){
            m.erase(l.back().key);
            l.pop_back();
            Node n(key,value);
            l.push_front(n);
            m[key]=l.begin();
        }else{
            Node n(key,value);
        
             l.push_front(n);
            m[key]=l.begin();
        }}
         
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */