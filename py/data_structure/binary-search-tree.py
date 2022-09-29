from collections import deque
# 首先定义树的根节点


class Node(object):
    """docstring for Node"""

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 定义一棵二叉树


class BinarySearchTree(object):
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
        """广度遍历: 方法同add, 是一种反过来的操作
        """
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
        """广度遍历: 方法同add, 是一种反过来的操作
        """
        # 使用队列
        q = [self.root]
        if self.root is None:
            return
        level = 1
        while q:
            print(f"第{level}层元素: {[i.val for i in q]}")
            nq = []
            for cur_node in q:
                if cur_node.left:
                    nq.append(cur_node.left)
                if cur_node.right:
                    nq.append(cur_node.right)
            q = nq
            level += 1

    def breadth_travel2(self):
        """广度遍历: 方法同add, 是一种反过来的操作
        """
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

    def pre_order(self, node):
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
        recur_0(node)
        print(ret)

    def in_order(self, node):
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
        recur_1(node)
        print(ret)

    def post_order(self, node):
        """后序遍历"""
        # 递归遍历跳出的条件
        # if node is None:
        #     return
        # self.pre_order(node.left)
        # self.pre_order(node.right)
        # print(node.val, end=" ")
        ret = []

        def recur(node):
            if node:
                recur(node.left)
                recur(node.right)
                ret.append(node.val)
        recur(node)
        print(ret)

    def pre_order_1(self, node):
        """前序遍历(中左右): 非递归, 需要使用栈(递归的本质是栈实现)来实现"""
        # 定义一个栈
        st = []
        # 定义顺序数组
        result_arr = []
        if node:
            st.append(node)
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

    def in_order_1(self, node):
        """中序遍历(左中右), 需要指针(由于遍历的节点顺序和处理的节点顺序不同)"""
        st = []
        result_arr = []
        cur_node = node
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

    def in_order_2(self, node):
        """中序遍历(左中右), 通解"""
        st = []
        result_arr = []
        if node:
            st.append(node)
        while st:
            node = st[-1]
            if node:
                st.pop()
                if node.right:
                    st.append(node.right)
                st.append(node)
                # 空节点入栈作为标记
                st.append(None)
                if node.left:
                    st.append(node.left)
            else:
                # 空节点出栈
                st.pop()
                node = st[-1]
                st.pop()
                result_arr.append(node.val)
        print(result_arr)

    def post_order_1(self, node):
        """后序遍历(左右中), 可以直接由前序遍历得到"""
        # 定义一个栈
        st = []
        # 定义顺序数组
        result_arr = []
        if node:
            st.append(node)
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

    def post_order_2(self, node):
        """后序遍历(左右中), 可以直接由前序遍历得到"""
        # 定义一个栈
        st = []
        # 定义顺序数组
        result_arr = []
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
