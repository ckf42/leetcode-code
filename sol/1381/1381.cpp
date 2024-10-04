struct CustomStack {
    int maxSize, ptr, stackTop;
    vector<int> diff;

    CustomStack(int maxSize):
        maxSize(maxSize),
        ptr(0),
        stackTop(-1),
        diff(maxSize) {}
    
    inline void push(int x) {
        if (this->ptr == this->maxSize){
            return;
        }
        this->diff[this->ptr++] = this->stackTop - x;
        this->stackTop = x;
    }
    
    inline int pop() {
        if (this->ptr == 0){
            return -1;
        }
        int buff = this->stackTop;
        this->stackTop += this->diff[--this->ptr];
        return buff;
    }
    
    inline void increment(int k, int val) {
        if (k >= this->ptr){
            this->stackTop += val;
        } else {
            this->diff[k] += val;
        }
    }
};

