#include <queue>

struct Solution {
    using l = long;
    int minOperations(vector<int>& nums, int k) {
        priority_queue<l, vector<l>, std::greater<l>> q;
        for (int x : nums){
            q.push(x);
        }
        int res = 0;
        while (q.top() < k){
            l x = q.top();
            q.pop();
            l y = q.top();
            q.pop();
            q.push(x * 2 + y);
            ++res;
        }
        return res;
    }
};
