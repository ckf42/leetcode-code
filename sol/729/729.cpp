#include <set>

struct MyCalendar {
    set<pair<int, int>> data;

    MyCalendar(): data() {}
    
    bool book(int start, int end) {
        auto it = this->data.lower_bound({start, end});
        if ((it != this->data.begin() && std::prev(it)->second > start)
                || (it != this->data.end() && it->first < end)){
            return false;
        }
        this->data.insert({start, end});
        return true;
    }
};

