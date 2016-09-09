/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize_recur(string &s, int lhs, int rhs) {
        NestedInteger nest;
        if(s[lhs] != '[') {
            nest.setInteger(atoi(s.substr(lhs, rhs-lhs).c_str()));
            return nest;
        }
        lhs++;
        rhs--;
        while(lhs < rhs) {
            int pos = lhs;
            if(s[lhs] != '[') {
                while(pos < rhs && s[pos] != ',') {
                    pos++;
                }
                if(pos == rhs) {
                    nest.add(atoi(s.substr(lhs, rhs-lhs).c_str()));
                    break;
                } 
            } else {
                stack<char> stk;
                stk.push('[');
                pos++;
                while(!stk.empty()) {
                    if(s[pos] == '[') {
                        stk.push('[');
                    } else if (s[pos] == ']') {
                        stk.pop();
                    }
                    pos++;
                }
            }
            nest.add(deserialize_recur(s, lhs, pos));
            lhs = pos+1;
        }
        return nest;
    }
    
    NestedInteger deserialize(string s) {

        return deserialize_recur(s, 0, s.size());
    }
};
