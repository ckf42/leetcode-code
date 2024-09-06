class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        targets = frozenset(nums)
        foo = ListNode(-1, head)
        prev = foo
        ptr = head
        while ptr is not None:
            if ptr.val in targets:
                ptr = ptr.next
                prev.next = ptr
            else:
                prev = ptr
                ptr = ptr.next
        return foo.next
