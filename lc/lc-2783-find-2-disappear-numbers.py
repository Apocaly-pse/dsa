from typing import List
from math import sqrt


class Solution:
    def missingTwo(self, nums: List[int]) -> List[int]:  # hash
        nums += [-1] * 3
        for i in range(n := len(nums)):
            while (ni := nums[i]) != i and ni != -1:
                nums[i], nums[ni] = nums[ni], nums[i]
        return [i for i in range(1, n) if nums[i] == -1]

    def missingTwo4(self, nums: List[int]) -> List[int]:  # set
        return list(set(range(1, len(nums) + 3)) - set(nums))

    def missingTwo3(self, nums: List[int]) -> List[int]:  # xor
        xorsum = 0
        n = len(nums) + 2
        for num in nums:
            xorsum ^= num
        for i in range(1, n + 1):
            xorsum ^= i

        lsb = xorsum & (-xorsum)  # 取最低位lowbit
        type1 = 0
        for num in nums:
            if num & lsb:
                type1 ^= num
        for i in range(1, n + 1):
            if i & lsb:
                type1 ^= i

        return [type1, xorsum ^ type1]

    def missingTwo2(self, nums: List[int]) -> List[int]:  # math
        n = len(nums) + 2
        sumTwo = n * (n + 1) // 2 - sum(nums)
        lmt = sumTwo // 2
        total = 0
        for i in nums:
            if i <= lmt:
                total += i
        one = lmt * (lmt + 1) // 2 - total
        return [one, sumTwo - one]

    def missingTwo1(self, nums: List[int]) -> List[int]:  # math
        su = ((n := len(nums)) + 2) * (n + 3) // 2 - sum(nums)  # s1+s2
        squ = (n + 2) * (n + 3) * (2 * n + 5) // 6 - \
            sum(map(lambda x: x * x, nums))  # s1*s1+s2*s2
        sm = sqrt(2 * squ - su * su)
        return [int((su + sm) // 2), int(abs(su - sm) // 2)]


if __name__ == '__main__':
    s = Solution().missingTwo3
    print(s([1]))
    print(s([1, 4]))
