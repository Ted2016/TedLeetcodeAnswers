class MedianFinder {
private:
    priority_queue<int, vector<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    bool isEven;
    int mid;
public:
    MedianFinder(): isEven(true) {
        max_heap.push(INT_MIN);
        min_heap.push(INT_MAX);
    }
    // Adds a number into the data structure.
    void addNum(int num) {
        
        if(isEven) {
            int min = min_heap.top(), max = max_heap.top();
            if(num > min) {
                mid = min;
                min_heap.pop();
                min_heap.push(num);
            } else if(num < max) {
                mid = max;
                max_heap.pop();
                max_heap.push(num);
            } else {
                mid = num;
            }
        } else {
            if(num > mid) {
                max_heap.push(mid);
                min_heap.push(num);
            } else {
                max_heap.push(num);
                min_heap.push(mid);
            }
        }
        isEven = !isEven;
    }


    // Returns the median of current data stream
    double findMedian() {
        double min = static_cast<double>(min_heap.top()), max = static_cast<double>(max_heap.top());
        if(isEven) {
            return min+(max-min)/2;
        } else {
            return mid;
        }
    }
};