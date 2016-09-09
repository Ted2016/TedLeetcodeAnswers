class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, size_t> table1;
        for(auto iter = nums.begin(); iter != nums.end(); iter++) {
            table1[*iter]++;
        }
        vector <pair<int, size_t>> table(table1.begin(), table1.end());
        partial_sort(table.begin(), table.begin()+k, table.end(), 
        [](const pair<int, size_t> &item1, const pair<int, size_t> &item2) {return item1.second > item2.second;});
        vector<int> ret;
        for_each(table.begin(), table.begin()+k, [&ret](const pair<int, size_t> &item) {ret.push_back(item.first);});
        return ret;
    }
};