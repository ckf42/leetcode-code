#include <queue>

struct SeatManager {
    priority_queue<int> q;

    SeatManager(int n) {
        for (int i = 1; i <= n; ++i){
            q.push(-i);
        }
    }
    
    int reserve(void) {
        int top = this->q.top();
        q.pop();
        return -top;
    }
    
    void unreserve(int seatNumber) {
        this->q.push(-seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
