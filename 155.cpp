#include <stack>

struct MinStack {
    stack<int> data, order;
    MinStack(): data(), order() {}
    
    void push(int val) {
        this->data.push(val);
        if (this->order.empty() || this->order.top() >= val){
            this->order.push(val);
        }
    }
    
    inline void pop() {
        if (this->order.top() == this->data.top()){
            this->order.pop();
        }
        this->data.pop();
    }
    
    inline int top(void) const { return this->data.top(); }
    
    inline int getMin(void) const { return this->order.top(); }
};

