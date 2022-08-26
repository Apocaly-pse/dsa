
MAXN = 10

fa = [0] * MAXN  # 记录某个人的爸爸是谁，特别规定，祖先的爸爸是他自己


# init
def makeSet(size):
    for i in range(size):
        fa[i] = i  # 初始化:自己是自己的祖先
    return


def find_recur(x):
    # 递归
    # 寻找x的祖先
    if fa[x] == x:
        return x  # 如果x是祖先则返回
    else:
        return find_recur(fa[x])  # 如果不是则 x 的爸爸问 x 的爷爷


def find_iter(x):
    # 非递归
    while x != fa[x]:  # 如果 x 不是祖先，就一直往上一辈找
        x = fa[x]
    return x  # 如果 x 是祖先则返回


def find_1(i):
    # 路径压缩
    if i == fa[i]:
        return i  # 递归出口,到达了祖先位置,返回祖先
    else:
        fa[i] = find_1(fa[i])  # 路径压缩
        return fa[i]  # 返回父节点


def union(i, j):
    i_fa = find_recur(i)
    j_fa = find_recur(j)
    fa[i_fa] = j_fa  # i的祖先指向j的祖先


if __name__ == '__main__':
    makeSet(10)
    for i in range(9):
        union(i, i + 1)
    print(find_1(3))
    print(fa)
