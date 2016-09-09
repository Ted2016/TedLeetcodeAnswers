class LRUCache{
public:
    LRUCache(int capacity): cap(capacity){
        
    }
    
    int get(int key) {
        auto iter = map.find(key);
        if(iter != map.end()) {
            auto curr = iter->second;
            lst.push_front(*curr);
            lst.erase(curr);
            map[key] = lst.begin();
            return lst.front().second;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        int n = get(key);
        if (n == -1) {
            auto item = make_pair(key, value);
            lst.push_front(item);
            map[key] = lst.begin();
            if(lst.size() > cap) {
                int k = lst.back().first;
                lst.pop_back();
                map.erase(map.find(k));
            }
        } else {
            lst.front().second = value;
            
        } 

    }
private:
   int cap;
   list<pair<int, int>> lst;
   unordered_map<int, list<pair<int, int>>::iterator> map;
};
