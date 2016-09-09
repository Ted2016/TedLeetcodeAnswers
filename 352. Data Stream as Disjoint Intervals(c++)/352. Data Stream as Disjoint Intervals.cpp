/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        ints.insert(val);
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> intervals{};
        if(ints.empty()) {
            return intervals;
        }
        auto iter = ints.begin();
        int begin = *iter, end = begin;
        Interval interval;
        iter++;
        while(iter != ints.end()) {
            if(*iter > end+1) {
                interval.start = begin;
                interval.end = end;
                intervals.push_back(interval);
                begin = *iter, end = begin;
            } else {
                end++;
            }
            iter++;
        }
        interval.start = begin;
        interval.end = end;
        intervals.push_back(interval );
        return intervals;
    }
private:
    set<int> ints;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */