class RandomizedSet {
     private:
set<int> s;
public:
   
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto vall = s.find(val);
        if (vall != s.end())
            return false;

        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        auto itr = s.find(val);
        if (itr == s.end())
            return false;

        s.erase(itr);
        return true;
        
    }
    
    int getRandom() {
        if (s.empty()) {
            // You can handle this case based on your requirements
            // For now, let's return -1 to indicate an empty set
            return -1;
        }

        // Generate a random index
        std::size_t randomIndex = std::rand() % s.size();

        // Create an iterator and move it to the random index
        auto itr = s.begin();
        std::advance(itr, randomIndex);

        // Return the value at the random index
        return *itr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */