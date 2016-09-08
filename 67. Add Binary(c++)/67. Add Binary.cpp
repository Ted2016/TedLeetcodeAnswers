class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() > b.size()) {
            return addBinary(b, a);
        }
        auto iter_a = a.rbegin(), iter_b = b.rbegin();
        string ret;
        bool add_1 = false;
        while(iter_a != a.rend()) {
            if(*iter_a == '1' && *iter_b == '1') {
                ret.insert(ret.begin(), add_1? '1' :'0');
                add_1 = true;
            } else if(*iter_a == '0' && *iter_b == '0') {
                ret.insert(ret.begin(), add_1? '1' :'0');
                add_1 = false;
            } else {
                ret.insert(ret.begin(), add_1? '0' :'1');
                add_1 = add_1? true : false;
            }
            iter_a++;
            iter_b++;
        }
        if(add_1) {
            while(iter_b != b.rend() && *iter_b == '1') {
                iter_b++;
                ret.insert(ret.begin(), '0');
            }
            ret.insert(ret.begin(), '1');
            if(iter_b != b.rend()) {
                ret.insert(ret.begin(), b.begin(), (iter_b+1).base());
            }
        } else {
            ret.insert(ret.begin(), b.begin(), iter_b.base());
        }
        return ret;
    }
};