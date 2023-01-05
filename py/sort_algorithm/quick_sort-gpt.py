
def quick_sort(arr):
    # 快速排序算法
    if len(arr) <= 1:
        return arr
    pivot = arr[0]
    left = [x for x in arr if x < pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + [pivot] + quick_sort(right)


arr = [5, 3, 7, 1, 9, 2, 8, 4, 6]
arr = quick_sort(arr)
print(arr)
# 输出 [1, 2, 3, 4, 5, 6, 7, 8, 9]
