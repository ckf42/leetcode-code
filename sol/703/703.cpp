#include <queue>

struct KthLargest {
    int k;
    priority_queue<int, vector<int>, std::greater<int>> q;

    KthLargest(int k, vector<int>& nums):
        k(k) {
        for (int x : nums){
            q.push(x);
        }
        while (q.size() > k){
            q.pop();
        }
    }
    
    inline int add(int val) {
        q.push(val);
        while (q.size() > k){
            q.pop();
        }
        return q.top();
    }
};

