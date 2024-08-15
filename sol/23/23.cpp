#include <queue>

struct Solution {
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode foo(0);
        ListNode *ptr = &foo;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < lists.size(); ++i){
            if (lists[i] != nullptr){
                pq.push({-lists[i]->val, i});
            }
        }
        while (!pq.empty()){
            auto [v, i] = pq.top();
            pq.pop();
            ptr->next = new ListNode(-v);
            ptr = ptr->next;
            lists[i] = lists[i]->next;
            if (lists[i] != nullptr){
                pq.push({-lists[i]->val, i});
            }
        }
        return foo.next;
    }
};
