/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs) {
            return lhs.end > rhs.end;
        });
         stable_sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs) {
            return lhs.start < rhs.start;
        });
        auto iter = unique(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs) {
            return lhs.start == rhs.start;
        });
        intervals.erase(iter, intervals.end());
        for(auto iter = intervals.begin()+1; iter != intervals.end(); iter++) {
            auto prev = iter-1;
            if(prev->end >= iter->start) {
                prev->end = max(prev->end, iter->end);
                intervals.erase(iter);
                iter = prev;
            }
        }
        return intervals;
    }
};