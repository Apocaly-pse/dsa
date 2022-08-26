from typing import List


def CountSort(A: List[int], w: int) -> List[int]:
    # init
    cnt = [0] * (w + 1)
    n = len(A)
    Sorted_A = [0] * n
    # Counting
    for i in range(n):
        cnt[A[i]] += 1
    # calc prefix-sum
    for i in range(1, w + 1):
        cnt[i] += cnt[i - 1]
    # print(cnt)
    for i in range(n - 1, -1, -1):
        Sorted_A[cnt[A[i]] - 1] = A[i]
        cnt[A[i]] -= 1
    return Sorted_A


if __name__ == '__main__':
    a1 = [3, 3, 2, 2, 1, 4, 5, 5, 7, 0]
    print(CountSort(a1, 7))
