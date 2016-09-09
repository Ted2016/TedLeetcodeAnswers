/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int_vector = flatten(nestedList);

    }

    int next() {
       int ret = int_vector.back();
       int_vector.pop_back();
       return ret;
    }

    bool hasNext() {
        return ! int_vector.empty();
    }
    
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        vector<int> i_vector;
        for(int i = nestedList.size()-1; i >= 0; i--) {
            if (nestedList[i].isInteger()) {
                i_vector.push_back(nestedList[i].getInteger());
            } else {
                vector<int> temp = flatten(nestedList[i].getList());
                i_vector.insert(i_vector.end(), temp.begin(), temp.end());
            }
            
        }
        return i_vector;
    }
    
private:
    vector<int> int_vector;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */