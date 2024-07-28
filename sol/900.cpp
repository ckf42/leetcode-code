struct RLEIterator {
    vector<int>& data;
    size_t ptr;
    size_t N;

    RLEIterator(vector<int>& encoding): data(encoding), ptr(0) {
        this->N = this->data.size();
    }
    
    int next(int n) {
        int lastOut = -1;
        while (this->ptr < this->N){
            if (n <= this->data[this->ptr]){
                this->data[this->ptr] -= n;
                return this->data[this->ptr + 1];
            } else {
                n -= this->data[this->ptr];
                lastOut = this->data[++(this->ptr)];
                ++(this->ptr);
            }
        }
        return (n == 0 ? lastOut : -1);
    }
};
