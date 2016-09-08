class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            while(!que.empty() && nums[que.back()] <= nums[i]) {
                que.pop_back();
            }
            que.push_back(i);
            if(que.front() < i-k+1) {
                que.pop_front();
            }
            if(i >= k-1) {
                result.push_back(nums[que.front()]);
            }
        }
        
        return result;
    }
};