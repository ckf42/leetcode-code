class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        n1 = len(str1)
        n2 = len(str2)
        ptr2 = 0
        for ptr1 in range(n1):
            if n1 - ptr1 < n2 - ptr2:
                break
            if str1[ptr1] == str2[ptr2] \
                    or (ord(str1[ptr1]) - ord('a') + 1) % 26 == ord(str2[ptr2]) - ord('a'):
                ptr2 += 1
            if ptr2 == n2:
                return True
        return False
