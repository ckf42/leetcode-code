struct Solution {
   ListNode *tail(ListNode *node, int &tailmax){
       if (node->next == nullptr){
           tailmax = node->val;
           return node;
       }
       ListNode *tailhead = tail(node->next, tailmax);
       if (node->val >= tailmax){
           node->next = tailhead;
           tailhead = node;
           tailmax = node->val;
       }
       return tailhead;
   }

   inline ListNode* removeNodes(ListNode* head) {
       int tailmax;
       return tail(head, tailmax);
   }
};
