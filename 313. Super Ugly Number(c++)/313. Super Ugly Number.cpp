struct node {
    int val;
    int prime;
    int nth;
    node(int v, int p, int n) : val(v), prime(p), nth(n) {
        
    }
};

struct cmp {
    bool operator()(node &n1, node &n2) {
        return n1.val > n2.val;
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<node, vector<node>, cmp> pq;
        vector<int> ugly{1};
        int size = primes.size();
        for(int i = 0; i < size; i++) {
            node tmp (primes[i], primes[i], 0);
            pq.push(tmp);
        }
        for(int i = 1; i < n; i++) {
            node tmp = pq.top();
            ugly.push_back(tmp.val);
            while(tmp.val == pq.top().val) {
                 tmp = pq.top();
                 pq.pop();
                 pq.push(node(tmp.prime*ugly[tmp.nth+1], tmp.prime, tmp.nth+1));
            }
            
        }
        return ugly.back();
    }
};






