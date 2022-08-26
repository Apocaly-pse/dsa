from typing import List


def getBitCnt(num: int) -> int:
    ans = 0
    while num:
        num //= 10
        ans += 1
    return ans


def CountSort(A: List[int], bitArr: List[int]) -> List[int]:
    # init
    w = max(bitArr)
    cnt = [0] * (w + 1)
    N = len(bitArr)
    Sorted_A = [0] * N

    # Counting
    for i in range(N):
        cnt[bitArr[i]] += 1

    # calc prefix-sum
    for i in range(1, w + 1):
        cnt[i] += cnt[i - 1]

    # print(cnt)
    for i in range(N - 1, -1, -1):
        Sorted_A[cnt[bitArr[i]] - 1] = A[i]
        cnt[bitArr[i]] -= 1
    return Sorted_A


def RadixSort(arr: List[int]) -> List[int]:
    bitMax = getBitCnt(max(arr))

    # print(bitMax)
    for i in range(1, bitMax + 1):
        bit_arr = list(map(lambda x: (x % (10 ** i)) // (10**(i - 1)), arr))
        arr = CountSort(arr, bit_arr)
        print(bit_arr, arr)


if __name__ == '__main__':
    a1 = [53, 3, 542, 750, 14, 214, 154, 63, 612]
    RadixSort(a1)
