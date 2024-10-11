struct Solution {
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> idx(n);
        ranges::iota(idx, 0);
        ranges::sort(idx, [&](int i, int j){return times[i][0] < times[j][0];});
        int nextChair = 0;
        vector<pair<int, int>> peopleHeap;
        vector<int> chairHeap;
        for (int i : idx){
            int chair = -1;
            while (!peopleHeap.empty() && -peopleHeap.front().first <= times[i][0]){
                ranges::pop_heap(peopleHeap);
                chairHeap.push_back(peopleHeap.back().second);
                ranges::push_heap(chairHeap);
                peopleHeap.pop_back();
            }
            if (chairHeap.empty()){
                chair = (nextChair++);
            } else {
                ranges::pop_heap(chairHeap);
                chair = -chairHeap.back();
                chairHeap.pop_back();
            }
            peopleHeap.emplace_back(-times[i][1], -chair);
            ranges::push_heap(peopleHeap);
            if (i == targetFriend){
                return chair;
            }
        }
        return -1;
    }
};
