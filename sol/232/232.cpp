struct MyQueue {
    vector<int> head, tail;
    MyQueue(): head(), tail() {}
    
    inline void push(int x) {
        this->tail.push_back(x);
    }
    
    int pop() {
        this->peek();
        int val = this->head.back();
        this->head.pop_back();
        return val;
    }
    
    int peek() {
        if (this->head.empty()){
            while (!this->tail.empty()){
                this->head.push_back(this->tail.back());
                this->tail.pop_back();
            }
        }
        return this->head.back();
    }
    
    inline bool empty() const {
        return this->head.empty() && this->tail.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
