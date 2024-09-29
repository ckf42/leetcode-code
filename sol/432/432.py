class AllOne:
    class AllOneNode:
        def __init__(self, freq):
            self.freq = freq
            self.prev = None
            self.next = None
            self.items = set()

    def __init__(self):
        self.head = AllOne.AllOneNode(0)
        self.tail = AllOne.AllOneNode(0)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.nodeMap = dict()

    def __insertAfter(self, node, freq):
        newNode = self.AllOneNode(freq)
        newNode.next = node.next
        newNode.prev = node
        node.next.prev = newNode
        node.next = newNode
        return newNode

    def __remove(self, node):
        p = node.prev
        n = node.next
        p.next = n
        n.prev = p

    def inc(self, key: str) -> None:
        if key not in self.nodeMap:
            ptr = self.head.next
            if ptr == self.tail or ptr.freq != 1:
                ptr = self.__insertAfter(self.head, 1)
            ptr.items.add(key)
            self.nodeMap[key] = ptr
        else:
            node = self.nodeMap[key]
            freq = node.freq
            node.items.remove(key)
            ptr = node.next
            if ptr == self.tail or ptr.freq != freq + 1:
                ptr = self.__insertAfter(node, freq + 1)
            ptr.items.add(key)
            self.nodeMap[key] = ptr
            if len(node.items) == 0:
                self.__remove(node)

    def dec(self, key: str) -> None:
        node = self.nodeMap.get(key, None)
        if node is None:
            return
        freq = node.freq
        node.items.remove(key)
        if freq == 1:
            del self.nodeMap[key]
        else:
            ptr = node.prev
            if ptr == self.head or ptr.freq != freq - 1:
                ptr = self.__insertAfter(ptr, freq - 1)
            ptr.items.add(key)
            self.nodeMap[key] = ptr
        if len(node.items) == 0:
            self.__remove(node)

    def getMaxKey(self) -> str:
        if self.head.next == self.tail:
            return ""
        return next(iter(self.tail.prev.items))

    def getMinKey(self) -> str:
        if self.head.next == self.tail:
            return ""
        return next(iter(self.head.next.items))


