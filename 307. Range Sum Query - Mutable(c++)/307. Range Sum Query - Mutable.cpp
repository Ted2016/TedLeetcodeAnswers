class NumArray {
public:
    NumArray(vector<int> &nums) : Nums(nums) {
        
    }

    void update(int i, int val) {
        if (i < 0 || i >= Nums.size()) {
            return;
        }
        else {
            Nums[i] = val;
        }
    }

    int sumRange(int i, int j) {
        return accumulate(Nums.cbegin()+i, Nums.cbegin()+j+1, 0);
    }
private:
    vector<int> Nums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);