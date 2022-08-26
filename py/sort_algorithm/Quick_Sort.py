"""
快速排序:
采用`递归`的方法, 使用左右两个指针不断向中间遍历,
判断指针指向的元素与pivot的大小, 并进行交换,
逐渐减小问题规模, 以达到排序目的
"""


def Partition(R: list, m: int, n: int) -> int:
    i = m
    j = n + 1
    K = R[m]
    while i < j:
        i += 1
        while R[i] <= K and i <= n:
            i += 1
        j -= 1
        while R[j] > K and j >= 0:
            j -= 1
        if i < j:
            R[i], R[j] = R[j], R[i]
    R[m], R[j] = R[j], R[m]
    return j


def QuickSort(R, m, n):
    if m < n:
        j = Partition(R, m, n)
        QuickSort(R, m, j - 1)
        QuickSort(R, j + 1, n)


a = [54, 26, 93, 17, 77, 31, 44, 55, 20]

print(a)
QuickSort(a, 0, len(a) - 1)
print(a)
