from math import comb


class Solution:
    def countDigitOne(self, n: int) -> int:
        if n == 0:
            return 0

        def count1(A, B):
            # num=A*10^B
            if A == 0:
                return 0
            elif B == 0:
                return 1
            elif A == 1:
                return B * 10**(B - 1) + 1
            else:
                A -= 1
                tmp = 9**B + A * 9**(B - 1) * B + B + 1
            for i in range(2, B + 1):
                tmp += i * (9**(B - i + 1) * comb(B, i - 1)) + \
                    i * (A * 9**(B - i) * comb(B, i))
            return tmp

        def digit(n):
            # 计算位数
            arr = []
            while n:
                arr.append(n % 10)
                n //= 10
            return arr
        arr = digit(n)
        dgt = len(arr)
        ans = 0
        flag1 = 0
        for i in range(dgt - 1, -1, -1):
            ans += count1(arr[i], i)
            flag1 += 1 if arr[i] == 1 else 0
            if i > 0 and flag1:
                ans += arr[i - 1] * flag1 * 10**(i - 1)
        return ans


if __name__ == '__main__':
    s = Solution().countDigitOne
    # print(s(20000), 18000)
    # print(s(40000), 26000)
    print(s(41111), 26448)  # 26448
    print(s(23131), 19966)  # 19966
    print(s(839103938), 777456133)  # 777456133
    print(s(211111), 205560)
    print(s(11), 4)  # 4
    print(s(111), 36)  # 33
    print(s(21), 13)  # 13
    print(s(1), 1)  # 1
    print(s(13), 6)  # 6
    print(s(211), 144)  # 144
    print(s(2111), 1636)  # 1636
    print(s(1111), 448)  # 448
    print(s(120), 53)  # 53
    print(s(342), 175)  # 175
    print(s(1202), 644)  # 644
    print(s(103), 25)  # 25
    print(s(113), 40)  # 40
    # print(s(0), 0)  # 0
