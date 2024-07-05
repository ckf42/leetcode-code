struct Solution {
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCrit = -1, lastCrit = -1, minDist = 100001, i = 1, prevVal = head->val;
        ListNode *ptr = head->next, *nextPtr = head->next->next;
        while (nextPtr != nullptr){
            if ((ptr->val > prevVal && ptr->val > nextPtr->val) || (ptr->val < prevVal && ptr->val < nextPtr->val)){
                if (firstCrit == -1){
                    firstCrit = i;
                }
                if (lastCrit != -1){
                    minDist = min(minDist, i - lastCrit);
                }
                lastCrit = i;
            }
            prevVal = ptr->val;
            ++i;
            ptr = nextPtr;
            nextPtr = nextPtr->next;
        }
        if (firstCrit == -1 || firstCrit == lastCrit){
            return {-1, -1};
        } else {
            return {minDist, lastCrit - firstCrit};
        }
    }
};
