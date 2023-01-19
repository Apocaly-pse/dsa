from collections import deque

# 首先定义树的根节点


class Node(object):
    """docstring for Node"""

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# 定义一棵二叉树
class BinaryTree(object):
    """docstring for BinaryTree"""

    def __init__(self):
        # 根节点
        self.root = None

    def add(self, item):
        node = Node(item)
        # 向树中插入元素, 使用队列存储元素, 读取与弹出
        if not self.root:
            self.root = node
            return
        # 用顺序表实现队列, 先入先出FIFO
        queue = [self.root]

        while queue:
            cur_node = queue.pop(0)
            if cur_node.val is None:
                continue
            # 若当前节点的左孩子为空, 将节点赋给当前节点左孩子
            if not cur_node.left:
                cur_node.left = node
                return
            else:
                queue.append(cur_node.left)
            if not cur_node.right:
                cur_node.right = node
                return
            else:
                queue.append(cur_node.right)

    def breadth_travel(self):
        """广度遍历: 方法同add, 是一种反过来的操作"""
        # 使用队列
        queue = [self.root]
        ret = []
        if self.root is None:
            return
        while queue:
            cur_node = queue.pop(0)
            # 打印结点值
            # print(cur_node.val, end=" ")
            ret.append(cur_node.val)
            if cur_node.left:
                queue.append(cur_node.left)
            if cur_node.right:
                queue.append(cur_node.right)
        print(ret)

    def breadth_travel1(self):
        """广度遍历: 方法同add, 是一种反过来的操作"""
        # 使用队列
        q = [self.root]
        if self.root is None:
            return
        level = 1
        while q:
            nq = []
            for cur_node in q:
                if cur_node.left:
                    nq.append(cur_node.left)
                if cur_node.right:
                    nq.append(cur_node.right)
            print(f"第{level}层元素: {[i.val for i in q]}")
            q = nq
            level += 1

    def breadth_travel2(self):
        """广度遍历: 方法同add, 是一种反过来的操作"""
        # 使用队列
        q = deque([self.root])
        if self.root is None:
            return
        level = 1
        while q:
            print(f"第{level}层元素: {[i.val for i in q]}")
            for _ in range(len(q)):
                cur_node = q.popleft()
                if cur_node.left:
                    q.append(cur_node.left)
                if cur_node.right:
                    q.append(cur_node.right)
            level += 1

    def pre_order(self):
        """前序遍历: 递归方法"""
        # if node is None:
        #     return
        # print(node.val, end=" ")
        # self.pre_order(node.left)
        # self.pre_order(node.right)
        ret = []

        def recur_0(node):
            if node:
                ret.append(node.val)
                recur_0(node.left)
                recur_0(node.right)

        recur_0(self.root)
        print(ret)

    def in_order(self):
        """中序遍历"""
        # if node is None:
        #     return
        # self.in_order(node.left)
        # print(node.val, end=" ")
        # self.in_order(node.right)
        ret = []

        def recur_1(node):
            if node:
                recur_1(node.left)
                ret.append(node.val)
                recur_1(node.right)

        recur_1(self.root)
        print(ret)

    def post_order(self):
        """后序遍历"""
        # 递归遍历跳出的条件
        # if node is None:
        #     return
        # self.pre_order(node.left)
        # self.pre_order(node.right)
        # print(node.val, end=" ")
        ret = []

        def recur_2(node):
            if node:
                recur_2(node.left)
                recur_2(node.right)
                ret.append(node.val)

        recur_2(self.root)
        print(ret)

    def pre_order_1(self):
        """前序遍历(中左右): 非递归, 需要使用栈(递归的本质是栈实现)来实现"""
        # 定义一个栈
        st = []
        # 定义顺序数组
        result_arr = []
        if self.root:
            st.append(self.root)
        while st:
            node = st.pop()
            # 中
            result_arr.append(node.val)
            # 右
            if node.right:
                st.append(node.right)
            # 左
            if node.left:
                st.append(node.left)
        print(result_arr)

    def in_order_1(self):
        """中序遍历(左中右), 需要指针(由于遍历的节点顺序和处理的节点顺序不同)"""
        st = []
        result_arr = []
        cur_node = self.root  # 这里用指针是防止根节点被改变影响之后的操作
        while cur_node or st:
            if cur_node:
                # 利用指针访问结点,访问到最底层数据
                # 结点入栈
                st.append(cur_node)
                # 左
                cur_node = cur_node.left
            else:
                cur_node = st.pop()
                # 中
                result_arr.append(cur_node.val)
                # 右
                cur_node = cur_node.right
        print(result_arr)

    def in_order_2(self):
        """中序遍历(左中右), 通解"""
        st = []
        result_arr = []
        if self.root:
            st.append(self.root)
        while st:
            node = st.pop()
            if node:
                if node.right:
                    st.append(node.right)
                st.append(node)
                # 空节点入栈作为标记
                st.append(None)
                if node.left:
                    st.append(node.left)
            else:
                # 若为空节点,直接捕获下一个节点
                node = st.pop()
                result_arr.append(node.val)
        print(result_arr)

    def in_order_3(self):
        WHITE, GRAY = 0, 1
        res = []
        stack = [(WHITE, self.root)]
        while stack:
            color, node = stack.pop()
            if node is None:
                continue
            if color == WHITE:
                stack.append((WHITE, node.right))
                stack.append((GRAY, node))
                stack.append((WHITE, node.left))
            else:
                res.append(node.val)
        print(res)

    def in_order_4(self):
        res = []
        stack = [self.root]
        while stack:
            node = stack.pop()
            if isinstance(node, Node):
                stack.extend([node.right, node.val, node.left])
            elif isinstance(node, int):
                res.append(node)
        print(res)

    def post_order_1(self):
        """后序遍历(左右中),直接由前序遍历得到"""
        # 定义一个栈
        st = []
        # 定义顺序数组
        result_arr = []
        if self.root:
            st.append(self.root)
        while st:
            node = st.pop()
            # 中
            result_arr.append(node.val)
            # 左
            if node.left:
                st.append(node.left)
            # 右
            if node.right:
                st.append(node.right)
        print(result_arr[::-1])

    def post_order_2(self):
        """后序遍历(左右中)"""
        # 定义一个栈
        st = []
        # 定义顺序数组
        result_arr = []
        node = self.root
        while st or node:
            while node:
                st.append(node)
                # 遍历二叉树直到结点不再含有左节点(右节点)
                node = node.left if node.left else node.right
            node = st.pop()
            # 最后加入中结点
            result_arr.append(node.val)
            # 判断并开始遍历右节点(node指向右节点), 然后继续进行入栈操作(while内循环)
            node = st[-1].right if st and st[-1].left == node else None
        print(result_arr)

    def print_Tree(self):
        # m:层数
        # n:列数
        q = deque([self.root])
        m = 0
        while q:
            for _ in range(len(q)):
                cur = q.popleft()
                # if not (cur.left or cur.right): continue
                if cur.left:
                    q.append(cur.left)
                if cur.right:
                    q.append(cur.right)
            m += 1
        n = (1 << m) - 1
        ans = [[" "] * n for _ in range(m)]
        branch = [[" "] * n for _ in range(m)]
        bq = deque([[0, (n - 1) // 2, self.root, ""]])
        while bq:
            for _ in range(len(bq)):
                r, c, cur, slash = bq.popleft()
                if cur.val is None:
                    continue
                ans[r][c] = str(cur.val)
                # 叶结点不能对斜杠/反斜杠进行移动
                if r == m - 1:
                    branch[r][c] = slash
                else:
                    if slash == "/":
                        branch[r][c + 1] = slash
                    else:
                        branch[r][c - 1] = slash
                if cur.left:
                    bq.append([r + 1, c - 2 ** (m - r - 2), cur.left, "/"])
                if cur.right:
                    bq.append([r + 1, c + 2 ** (m - r - 2), cur.right, "\\"])

        for i in range(m):
            print("".join(branch[i]))
            print("".join(ans[i]))


if __name__ == "__main__":
    tree = BinaryTree()
    # for i in [63909, 43838, 4549, -31714, -99701, -96320, 88666, 75152,
    #           -14750, -12671, 60405, None, 29388, None, None, None,
    #           -83674, None, None, -83490, None, -49913, 86188, 84455,
    #           None, None, None, None, None, None, None, None, None,
    #           -36061, 91438, -75550]:
    #     tree.add(i)
    for i in [1, None, 2, None, 3, 4, 5]:
        tree.add(i)
    # for i in range(25):
    #     tree.add(chr(97 + i))

    tree.print_Tree()
    # for i in range(1, 8):
    # tree.add(i)
    # print("广度遍历0: ")
    # tree.breadth_travel()
    print("广度遍历1: ")
    tree.breadth_travel1()
    print("广度遍历2: ")
    tree.breadth_travel2()

    print("\n深度遍历: ")
    print("前序遍历: 递归")
    tree.pre_order()
    # print("前序遍历: 非递归")
    # tree.pre_order_1()

    print()
    print("中序遍历: 递归")
    tree.in_order()
    # print("中序遍历: 非递归, 用指针")
    # tree.in_order_1()
    # print("中序遍历: 非递归, 不需要指针")
    # tree.in_order_2()
    # print("中序遍历: 非递归, 颜色标记法")
    # tree.in_order_3()
    # print("中序遍历: 非递归, 颜色标记法(改进)")
    # tree.in_order_4()

    print()
    print("后序遍历: 递归")
    tree.post_order()
    # print("后序遍历: 非递归, 修改自前序")
    # tree.post_order_1()
    # print("后序遍历: 非递归, 直接写")
    # tree.post_order_2()

"""
广度遍历: 
0 1 2 3 4 5 6 7 8 
深度遍历: 
前序遍历: 递归
0 1 3 7 8 4 2 5 6 
中序遍历: 递归
7 3 8 1 4 0 5 2 6 
后序遍历: 递归
7 8 3 4 1 5 6 2 0 
前序遍历: 非递归
[0, 1, 3, 7, 8, 4, 2, 5, 6]
中序遍历: 非递归
[7, 3, 8, 1, 4, 0, 5, 2, 6]
后序遍历: 非递归
[7, 8, 3, 4, 1, 5, 6, 2, 0]
"""
