class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto iter = nums.rbegin();
        for(; iter != nums.rend()-1; iter++) {
            if (*iter > *(iter+1))
               break;
        }   
        if(iter == nums.rend()-1) {
            reverse(nums.rbegin(), nums.rend());
        } else {
            auto iter1 = find_if(nums.rbegin(), iter+1, [iter](int i){ return i > *(iter+1);}); 
            int temp = *iter1;
            *iter1 = *(iter+1);
            *(iter+1) = temp;
            reverse(nums.rbegin(), iter+1);
        }   
    }   

};
