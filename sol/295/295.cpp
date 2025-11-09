struct MedianFinder {
    int n = 0;
    vector<int> small, large;

    MedianFinder() {}
    
    void addNum(int num) {
        if ((++this->n) & 1){
            this->large.push_back(-num);
            ranges::push_heap(this->large);
            ranges::pop_heap(this->large);
            int x = -this->large.back();
            this->large.pop_back();
            this->small.push_back(x);
            ranges::push_heap(this->small);
        } else {
            this->small.push_back(num);
            ranges::push_heap(this->small);
            ranges::pop_heap(this->small);
            int x = this->small.back();
            this->small.pop_back();
            this->large.push_back(-x);
            ranges::push_heap(this->large);
        }
    }
    
    double findMedian() {
        if (this->n & 1){
            return this->small.front();
        } else {
            return (this->small.front() - this->large.front()) / 2.0;
        }
    }
};

