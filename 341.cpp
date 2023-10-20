#include <stack>

class NestedIterator {
private:
    stack<NestedInteger> content;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (vector<NestedInteger>::const_reverse_iterator it = nestedList.crbegin();
             it != nestedList.crend();
             ++it){
            this->content.push(*it);
        }
    }
    
    int next() {
        this->hasNext();
        NestedInteger ni = this->content.top();
        this->content.pop();
        return ni.getInteger();
    }
    
    bool hasNext() {
        while (!this->content.empty() && !this->content.top().isInteger()){
            vector<NestedInteger> data = this->content.top().getList();
            this->content.pop();
            for (vector<NestedInteger>::const_reverse_iterator it = data.crbegin();
                 it != data.crend();
                 ++it){
                this->content.push(*it);
            }
        }
        return !this->content.empty();
    }
};

