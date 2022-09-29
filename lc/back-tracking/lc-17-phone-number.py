from typing import List
from math import prod
from itertools import permutations


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        dic = {'2': "abc", '3': "def", '4': "ghi",
               '5': "jkl", '6': "mno", '7': "pqrs",
               '8': "tuv", '9': "wxyz"}
        tmp=''.join(dic[i] for i in digits)
        ans=list(permutations(tmp))
        # ans = [''] * prod(len(dic[i]) for i in digits)
        return ans
        # for i in range((n := len(digits)) - 1):
        #     for j in range(i + 1, n):
        #         ans[dic[i]] = 1
        # return


if __name__ == '__main__':
    s = Solution().letterCombinations
    print(s('23'))
    print(s('42'))
