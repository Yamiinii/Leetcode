class MyHashMap {
private:
vector<pair<int,int>> v;
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
         for (auto& pair : v) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        v.push_back({key,value});
    }
    
    int get(int key) {
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first==key)
                return v[i].second;
        }
        return -1;
    }
    
    void remove(int key) {

 // for (auto it = v.begin(); it != v.end(); ++it) {
 //            if (it->first == key) {
 //                v.erase(it); // Remove the pair with the specified key
 //                return;
 //            }
 //        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first==key)
              v[i].first=INT_MAX;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */