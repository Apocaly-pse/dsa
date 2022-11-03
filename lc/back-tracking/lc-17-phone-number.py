from typing import List
from math import prod
from time import sleep
# from itertools import permutations


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        dic = {'2': "abc", '3': "def", '4': "ghi",
               '5': "jkl", '6': "mno", '7': "pqrs",
               '8': "tuv", '9': "wxyz"}
        if (ld := len(digits)) == 1:
            return list(dic[digits])

        def bt(d):
            if len(path) == ld:
                ans.append(''.join(path))
                return
            for i in range(len(dic[digits[d]])):
                path.append(dic[digits[d]][i])
                bt(d + 1)
                path.pop()
        ans, path = [], []
        bt(0)
        return ans

    def letterCombinations1(self, digits: str) -> List[str]:
        if not digits:
            return []
        dic = {'2': "abc", '3': "def", '4': "ghi",
               '5': "jkl", '6': "mno", '7': "pqrs",
               '8': "tuv", '9': "wxyz"}
        if (ld := len(digits)) == 1:
            return list(dic[digits])
        # print(ld)
        ans_cnt = prod(len(dic[c]) for c in digits)
        ans = [''] * ans_cnt
        # print(ans_cnt);exit()
        if ld == 2:
            for i, c in enumerate(dic[digits[0]]):
                for j, d in enumerate(d2 := dic[digits[1]]):
                    ans[i * len(d2) + j] += c + d
        if ld == 3:
            for i, c in enumerate(dic[digits[0]]):
                for j, d in enumerate(d2 := dic[digits[1]]):
                    for k, e in enumerate(d3 := dic[digits[2]]):
                        ans[i * len(d2) * len(d3) + j * len(d3)
                            + k] += c + d + e
        if ld == 4:
            for i, c in enumerate(dic[digits[0]]):
                for j, d in enumerate(d2 := dic[digits[1]]):
                    for k, e in enumerate(d3 := dic[digits[2]]):
                        for m, f in enumerate(d4 := dic[digits[3]]):
                            ans[i * len(d2) * len(d3) * len(d4) + j * len(d3)
                                * len(d4) + k * len(d4) + m] += c + d + e + f
        # print(ans)
        # exit()
        return ans


if __name__ == '__main__':
    s = Solution().letterCombinations
    print(s('23'))
    # print(s('439'))
    # print(s('4999'))
