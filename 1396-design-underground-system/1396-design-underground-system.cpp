class UndergroundSystem {
public:
    map<pair<string,string>,pair<int,int>> t;
    map<int,pair<string,int>> s;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int time) {
        s[id]={stationName,time};
    }
    
    void checkOut(int id, string stationName, int time) {
        t[{s[id].first,stationName}].second+=(time-s[id].second);
        t[{s[id].first,stationName}].first++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return ((double)t[{startStation,endStation}].second/t[{startStation,endStation}].first);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */