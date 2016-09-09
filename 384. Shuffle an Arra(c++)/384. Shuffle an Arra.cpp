class Solution {
private: 
    const vector<int> original;
public:
    Solution(vector<int> nums) : original(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffle_nums = original;
        for(int i = shuffle_nums.size(); i > 1; i--) {
            int lhs = shuffle_nums.size()-i, rhs = rand()%i+lhs;
            int tmp = shuffle_nums[lhs];
            shuffle_nums[lhs] = shuffle_nums[rhs];
            shuffle_nums[rhs] = tmp;
        }
        return shuffle_nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */