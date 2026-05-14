class MedianFinder {
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (large.size() > 0 && num >= large.top())
            large.push(num);
        else small.push(num);
       if (small.size() > large.size() + 1) {
        large.push(small.top());
        small.pop();
       }
       if (large.size() > small.size()) {
        small.push(large.top());
        large.pop();
       }
       /*
       cout << "add " << num ;
       if (small.size() > 0) cout << "," << small.top();
       if (large.size() > 0) cout << "," << large.top();
       cout << endl;
       */
    }
    
    double findMedian() {
        if (small.size() == large.size()) {
            return 0.5 *(small.top() + large.top());
        }
        return small.top();
    }
};
