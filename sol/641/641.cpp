struct MyCircularDeque {
    int k, l;
    vector<int> data;
    int begin;
    int end;


    MyCircularDeque(int k): 
        k(k), l(k + 1),
        data(k + 1, -1),
        begin(0), end(0) {}
    
    inline bool insertFront(int value) {
        if (this->isFull()){
            return false;
        }
        this->begin = (this->begin + this->k) % this->l;
        this->data[this->begin] = value;
        return true;
    }
    
    inline bool insertLast(int value) {
        if (this->isFull()){
            return false;
        }
        this->data[this->end] = value;
        this->end = (this->end + 1) % this->l;
        return true;
    }
    
    inline bool deleteFront() {
        if (this->isEmpty()){
            return false;
        }
        this->begin = (this->begin + 1) % this->l;
        return true;
    }
    
    inline bool deleteLast() {
        if (this->isEmpty()){
            return false;
        }
        this->end = (this->end + this->k) % this->l;
        return true;
    }
    
    inline int getFront() const {
        return this->isEmpty() ? -1 : this->data[this->begin];
    }
    
    inline int getRear() const {
        return this->isEmpty() ? -1 : this->data[(this->end + this->k) % this->l];
    }
    
    inline bool isEmpty() const {
        return this->begin == this->end;
    }
    
    inline bool isFull() const {
        return (this->end - this->begin + this->l) % this->l == this->k;
    }
};

