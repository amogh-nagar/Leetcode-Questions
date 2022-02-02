class StockPrice {
public:
    map<int,int> m;
    set<pair<int,int>> s;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        auto x=s.find({m[timestamp],timestamp});
        if(x!=s.end()){
            s.erase(x);
            
        }
        m[timestamp]=price;
        s.insert({price,timestamp});
    }
    
    int current() {
        
        return m.rbegin()->second;
    }
    
    int maximum() {
        
        return s.rbegin()->first;
    }
    
    int minimum() {
        
        return s.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */