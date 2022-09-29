from typing import List
from collections import Counter, defaultdict
'''
思路:
'''


class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 4:
            return n
        c = defaultdict(int)
        vc = defaultdict(int)
        maxCount = ans = 0
        for i in range(n):
            # ==================更新值==================
            if c[nums[i]]:  # 这一步是重点, 如果待存放的元素已经在c中,c中值+1之前要先去掉vc的值
                vc[c[nums[i]]] -= 1
            c[nums[i]] += 1
            maxCount = max(c[nums[i]], maxCount)
            vc[c[nums[i]]] += 1
            # ==================更新结束==================
            '''
            最大出现次数 maxFreq=1：那么所有数的出现次数都是一次，随意删除一个数既可符合要求。
            所有数的出现次数都是 maxFreq 或 maxFreq−1，并且最大出现次数的数只有一个：删除一个最大出现次数的数，那么所有数的出现次数都是maxFreq−1。
            除开一个数，其他所有数的出现次数都是 maxFreq，并且该数的出现次数为 1：直接删除出现次数为 1 的数，那么所有数的出现次数都是 maxFreq。
            '''
            if maxCount == 1 or\
                    vc[maxCount] * maxCount + vc[maxCount - 1] * (maxCount - 1) == i + 1 and vc[maxCount] == 1 or\
                    vc[maxCount] * maxCount == i and vc[1] == 1:
                ans = max(ans, i + 1)
        return ans

    s = Solution().maxEqualFreq
    print(s([2, 2, 1, 1]))  # 3
    print(s([2, 2, 1, 1, 5]))  # 5
    print(s([2, 2, 1, 1, 5, 3]))  # 5
    print(s([2, 2, 1, 1, 5, 3, 5]))  # 7
    print(s([2, 2, 1, 1, 5, 3, 3, 5]))  # 7
    print(s([1, 2, 3, 4, 5, 6, 7, 8, 9]))  # 9
    print(s([1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9]))  # 10
    print(s([1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5]))  # 13
