#include <algorithm>
#include <list>

struct MyHashSet {
    static constexpr unsigned capacity = 1 << 10;
    static constexpr unsigned mask = (1 << 10) - 1;
    list<int> table[capacity];

    MyHashSet() {}

    inline constexpr short _computeHash(int key){
        return ((key & mask) + 142) & mask;
    }
    
    void add(int key) {
        short k = this->_computeHash(key);
        list<int> &v = this->table[k];
        if (find(v.begin(), v.end(), key) == v.end()){
            v.push_front(key);
        }
    }
    
    void remove(int key) {
        short k = this->_computeHash(key);
        list<int> &v = this->table[k];
        list<int>::iterator it = find(v.begin(), v.end(), key);
        if (it != v.end()){
            v.erase(it);
        }
    }
    
    bool contains(int key) {
        short k = this->_computeHash(key);
        list<int> &v = this->table[k];
        return find(v.begin(), v.end(), key) != v.end();
    }
};

