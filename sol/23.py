import heapq as hq

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        foo = ListNode(0)
        ptr = foo
        h = [(x.val, i) for i, x in enumerate(lists) if x is not None]
        hq.heapify(h)
        while len(h) != 0:
            v, i = hq.heappop(h)
            ptr.next = ListNode(v)
            ptr = ptr.next
            lists[i] = lists[i].next
            if lists[i] is not None:
                hq.heappush(h, (lists[i].val, i))
        return foo.next
