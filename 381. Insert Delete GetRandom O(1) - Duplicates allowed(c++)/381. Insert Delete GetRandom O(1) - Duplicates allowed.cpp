class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto iter = mmap.find(val);
        ints.push_back(val);
        mmap.insert(make_pair(val, ints.size()-1));
        if(iter != mmap.end()) {
            return false;
        } else {
            return true;
        }
        
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto iter = mmap.find(val);
        if(iter == mmap.end()) {
            return false;
        }
        int size = ints.size()-1;
        auto itpair = mmap.equal_range(ints.back());
        for(; itpair.first != itpair.second && itpair.first->second != size; itpair.first++) {}
        ints[iter->second] = ints.back();
        ints.pop_back();
        itpair.first->second = iter->second;
        mmap.erase(iter);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int n = rand()%ints.size();
        return ints[n];
    }
private:
    vector<int> ints;
    unordered_multimap<int, int> mmap;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */