from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        # print(candidates)
        if sum(candidates) < target:
            return []
        n = len(candidates)

        # unique
        def bt(start):
            if start < n and candidates[start] > target:
                return
            if (sp := sum(path)) == target:
                if path not in ans:
                    ans.append(path[:])
                return
            if sp > target:
                return
            for i in range(start, n):
                if i and candidates[i] == candidates[i - 1] and used[i] == used[i - 1]:
                    continue
                path.append(candidates[i])
                used[i] = 1
                bt(i + 1)
                path.pop()
                used[i] = 0

        ans, path = [], []
        used = [0] * n
        bt(0)
        return ans


if __name__ == "__main__":
    s = Solution().combinationSum2
    print(s([1] * 100, 30))
    print(
        s(
            [
                14,
                6,
                25,
                9,
                30,
                20,
                33,
                34,
                28,
                30,
                16,
                12,
                31,
                9,
                9,
                12,
                34,
                16,
                25,
                32,
                8,
                7,
                30,
                12,
                33,
                20,
                21,
                29,
                24,
                17,
                27,
                34,
                11,
                17,
                30,
                6,
                32,
                21,
                27,
                17,
                16,
                8,
                24,
                12,
                12,
                28,
                11,
                33,
                10,
                32,
                22,
                13,
                34,
                18,
                12,
            ],
            27,
        )
    )
