class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = list()
        pushPtr = 0
        popPtr = 0
        while True:
            while popPtr < len(popped) and len(stack) != 0 and popped[popPtr] == stack[-1]:
                stack.pop()
                popPtr += 1
            if popPtr == len(popped):
                return True
            if pushPtr < len(pushed):
                stack.append(pushed[pushPtr])
                pushPtr += 1
            else:
                return False

