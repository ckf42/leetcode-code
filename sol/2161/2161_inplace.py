class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        n = len(nums)
        def rotate(s, m, e):  # [s, m)[m, e) -> [m, e)[s, m)
            if m == e:
                return
            ptr = m
            while ptr != s:
                nums[s], nums[ptr] = nums[ptr], nums[s]
                s += 1
                ptr += 1
                if ptr == e:
                    ptr = m
                elif s == m:
                    m = ptr
        def part(s: int, e: int) -> tuple[int, int]:
            if e - s <= 1:
                if nums[s] < pivot:
                    return (1, 0)
                elif nums[s] > pivot:
                    return (0, 1)
                return (0, 0)
            m = (s + e) // 2
            (s1, l1) = part(s, m)
            (s2, l2) = part(m, e)
            rotate(s + s1, m, m + s2)
            rotate(m - l1 + s2, m + s2, e - l2)
            return (s1 + s2, l1 + l2)
        part(0, n)
        return nums

