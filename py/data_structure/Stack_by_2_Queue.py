"""
栈的实现
通过两个队列实现
"""


class Stack(object):
    """
    1. 添加新元素item到栈顶: 压栈 push(item)
    2. 栈顶弹出元素: 出栈 pop()
    3. 返回栈顶元素: peek()
    4. 判断栈是否为空: is_empty()
    5. 返回栈的元素个数: size()
    """

    def __init__(self):
        # 初始化私有变量
        self.que1 = []
        self.que2 = []

    def push(self, item):
        # 需要在入队时候就进行操作
        if not self.que1:
            self.que1.append(item)
        else:
            self.que2.append(item)
            while self.que1:
                # 其实改成deque的popleft比较好
                self.que2.append(self.que1.pop(0))
            self.que1, self.que2 = self.que2, self.que1

    def pop(self):
        return self.que1.pop(0)

    def peek(self):
        if self.is_empty():
            return None
        else:
            return self.que1[0]

    def is_empty(self):
        return not self.que1

    def size(self):
        return len(self.que1)


if __name__ == "__main__":
    s = Stack()
    s.push(1)
    s.push(2)
    s.push(3)
    print(s.peek())
    print(s.pop())
    print(s.pop())
    print(s.peek())
    print(s.is_empty())
    print(s.size())
    """
    3
    3
    2
    1
    False
    1
    """

