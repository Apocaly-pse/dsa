"""
队列的实现
基于两个栈
"""


class Queue2stack(object):
    """docstring for Queue2stack"""

    def __init__(self):
        self.st_in = []
        self.st_out = []

    def enqueue(self, item):
        # in queue, directly
        self.st_in.append(item)

    def dequeue(self):
        # by using st_out
        if self.st_out:
            return self.st_out.pop()
        else:
            while self.st_in:
                self.st_out.append(self.st_in.pop())
            return self.st_out.pop()

    def peek(self):
        # head element
        # by dequeue()
        ans = self.dequeue()
        self.st_out.append(ans)
        return ans

    def is_empty(self):
        return not self.st_in and not self.st_out

    def size(self):
        return len(self.st_in) + len(self.st_out)


if __name__ == "__main__":
    q = Queue2stack()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    print(q.peek())
    print(q.size())
    print(q.dequeue())
    print(q.dequeue())
    print(q.is_empty())
    print(q.dequeue())
    print(q.is_empty())
    """
    1
    3
    1
    2
    False
    3
    True
    """
