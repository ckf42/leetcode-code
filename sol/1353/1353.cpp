struct Solution {
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        ranges::sort(events, [](auto &a, auto &b){return a[0] < b[0];});
        vector<int> h;
        int res = 0, currDay = 1, ptr = 0;
        while (true){
            if (h.empty() && ptr < n){
                currDay = events[ptr][0];
            }
            while (ptr < n && events[ptr][0] <= currDay){
                h.push_back(-events[ptr++][1]);
                ranges::push_heap(h);
            }
            while (!h.empty() && -h.front() < currDay){
                ranges::pop_heap(h);
                h.pop_back();
            }
            if (!h.empty() && -h.front() >= currDay){
                ranges::pop_heap(h);
                h.pop_back();
                ++res;
                ++currDay;
            }
            if (ptr == n && h.empty()){
                break;
            }
        }
        return res;
    }
};
