from typing import List
from math import pi

# from time import sleep


class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        def backtrack(start):
            if len(path) == k:
                if sum(path) == n:
                    ans.append(path[:])
                return
            # print((start, 9 + 2 - k + len(path)))
            for i in range(start, 9 + 2 - k + len(path)):
                # sleep(.5)
                path.append(i)
                backtrack(i + 1)
                path.pop()

        path, ans = [], []
        backtrack(1)
        return ans


"""
(1, 38)
(2, 39)
(3, 40)
(4, 41)
(5, 42)
(6, 43)
(7, 44)
(8, 45)
(9, 46)
(10, 46)
(11, 46)
(12, 46)
(13, 46)
(14, 46)
(15, 46)
(16, 46)
(17, 46)
(18, 46)
(19, 46)
(20, 46)
(21, 46)
(22, 46)


"""

if __name__ == "__main__":
    s = Solution().combinationSum3
    print(s(9, 45))
