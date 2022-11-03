from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        lc = len(candidates)

        def bt(start):
            if sum(path) == target:
                ans.append(path[:])
                return
            elif sum(path) > target:
                return

            for i in range(start, lc):
                path.append(candidates[i])
                bt(i)
                path.pop()
        ans, path = [], []
        bt(0)
        return ans


if __name__ == '__main__':
    s = Solution().combinationSum
    print(s([2, 3, 5, 7], 7))
