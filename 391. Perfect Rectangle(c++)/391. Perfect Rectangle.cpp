
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> hash;
        set<tuple<int, int, int, int>> thash;
        int area = 0;
        for(auto iter = rectangles.begin(); iter != rectangles.end(); iter++) {
            hash[make_pair((*iter)[0], (*iter)[1])]++;
            hash[make_pair((*iter)[2], (*iter)[3])]++;
            hash[make_pair((*iter)[0], (*iter)[3])]++;
            hash[make_pair((*iter)[2], (*iter)[1])]++;
            auto tp = make_tuple((*iter)[0], (*iter)[1], (*iter)[2], (*iter)[3]);
            if(thash.find(tp) != thash.end()) {
                return false;
            } else {
                thash.insert(tp);
            }
            area += ((*iter)[2]-(*iter)[0])*((*iter)[3]-(*iter)[1]);
        }
        int count = 0;
        int max_x = 0, min_x = INT_MAX, max_y = 0, min_y = INT_MAX;
        for(auto iter = hash.begin(); iter != hash.end(); iter++) {
            
            if(iter->second == 1) {
                count++;
                max_x = max(iter->first.first, max_x);
                max_y = max(iter->first.second, max_y);
                min_x = min(iter->first.first, min_x);
                min_y = min(iter->first.second, min_y);
            } else if(iter->second != 2 && iter->second != 4) {
                return false;
            } 
        }
        if(count == 4 && area == (max_x-min_x)*(max_y-min_y)) {
            return true;
        } else {
            return false;
        }
    }
};


