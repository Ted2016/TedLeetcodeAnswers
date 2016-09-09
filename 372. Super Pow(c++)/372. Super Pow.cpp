class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(a == 0) {
            return 0;
        } else if (a == 1) {
            return 1;
        }
        if(b[0] == 0) {
            return 1;
        } else if(b.size() == 1 && b[0] == 1) {
            return a % 1337;
        }
        bool add;
        divideTwo(b, add);
        a %= 1337;
        return (superPow(a*a, b)*(add ? a : 1))%1337;
    }
    
    void divideTwo(vector<int>& ints, bool& add) {
        int size = ints.size();
        add = false;
        for(int i = 0; i != size; i++) {
            int n = ints[i];
            ints[i] = (n/2 + (add ? 5 : 0));
            add = n%2;
        }
        if(ints[0] == 0) {
            ints.erase(ints.begin());
        }
    }
};