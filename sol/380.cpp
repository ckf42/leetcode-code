#include <unordered_map>
#include <random>

struct RandomizedSet {
    vector<int> items;
    unordered_map<int, int> index;
    mt19937 g;

    RandomizedSet(): g(std::random_device{}()) {}
    
    bool insert(int val) {
        if (this->index.contains(val)){
            return false;
        }
        this->index[val] = this->items.size();
        this->items.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!this->index.contains(val)){
            return false;
        }
        int last = this->items.back();
        this->items.pop_back();
        if (last != val){
            int k = this->index[val];
            this->index[last] = k;
            this->items[k] = last;
        }
        this->index.erase(val);
        return true;
    }
    
    int getRandom(void) {
        return this->items[this->g() % this->items.size()];
    }
};

