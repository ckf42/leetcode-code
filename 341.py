class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.stack = nestedList[::-1]

    def next(self) -> int:
        self.hasNext()
        return self.stack.pop().getInteger()

    def hasNext(self) -> bool:
        while len(self.stack) != 0 and not self.stack[-1].isInteger():
            ni = self.stack.pop()
            self.stack.extend(ni.getList()[::-1])
        return len(self.stack) != 0

# class NestedIterator:
#     class NestedIntegerYielder:
#         def __init__(self, data: NestedInteger):
#             self.data = data
# 
#         def __iter__(self) -> Iterator[int]:
#             if self.data.isInteger():
#                 yield self.data.getInteger()
#             else:
#                 for it in (self.__class__(content)
#                         for content in self.data.getList()):
#                     yield from it
# 
#     def __init__(self, nestedList: [NestedInteger]):
#         self.nestedList: list[NestedInteger] = nestedList
#         self.buffered: int | None = None
#         self.yielder: Generator[int] = (y
#             for content in self.nestedList
#             for y in self.NestedIntegerYielder(content))
# 
#     def next(self) -> int:
#         self.hasNext()
#         if self.buffered is not None:
#             temp = self.buffered
#             self.buffered = None
#             return temp
# 
#     def hasNext(self) -> bool:
#         if self.buffered is None:
#             self.buffered = next(self.yielder, None)
#         return self.buffered is not None

