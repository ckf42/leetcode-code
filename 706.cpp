#include <deque>
#include <utility>

struct MyHashMap {
    constexpr static unsigned CAPACITY = 1 << 10;
    constexpr static unsigned MASK = (1 << 10) - 1;

    vector<deque<pair<int, int>>> arr;

    MyHashMap() {
        arr.resize(CAPACITY);
    }

    constexpr unsigned __computeHash(int key) const {
        return ((key << 5) + key) & MASK;
    }
    
    void put(int key, int value) {
        unsigned h = this->__computeHash(key);
        deque<pair<int, int>> &q = arr[h];
        for (deque<pair<int, int>>::iterator it = q.begin();
             it != q.end();
             ++it){
            if (it->first == key){
                it->second = value;
                return;
            }
        }
        q.emplace_back(make_pair(key, value));
    }
    
    int get(int key) const {
        unsigned h = this->__computeHash(key);
        const deque<pair<int, int>> &q = arr[h];
        for (deque<pair<int, int>>::const_iterator it = q.cbegin();
             it != q.cend();
             ++it){
            if (it->first == key){
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        unsigned h = this->__computeHash(key);
        deque<pair<int, int>> &q = arr[h];
        for (deque<pair<int, int>>::const_iterator it = q.cbegin();
             it != q.cend();
             ++it){
            if (it->first == key){
                q.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
