class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val) != map.end()) {
            return false;
        } else {
            lst.push_back(val);
            map[val] = lst.end()-1;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto map_iter = map.find(val);
        if(map_iter != map.end()) {
            auto iter = map[val];
            lst.erase(iter);
            map.erase(map_iter);
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int n = lst.size();
        srand((int)time(0));
        return *(lst.begin() + rand()%n);
    }
private:
    unordered_map<int, vector<int>::iterator> map;
    vector<int> lst;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */