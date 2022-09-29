from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def backtrack(start):
            if len(path) == k:
                ans.append(path[:])
                return
            for i in range(start, n + 2 - k + len(path)):
                # 保证搜索的集合元素个数大等k
                path.append(i)
                backtrack(i + 1)
                path.pop()
        path, ans = [], []
        backtrack(1)
        return ans


if __name__ == '__main__':

    s = Solution().combine
    print(s(4, 2))
