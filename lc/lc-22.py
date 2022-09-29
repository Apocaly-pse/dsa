from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 1:
            return ['()']
        dp = set()
        for i in self.generateParenthesis(n - 1):
            for j in range(len(i) // 2 + 1):
                dp.add(i[:j] + '()' + i[j:])
        return list(dp)


if __name__ == '__main__':
    s = Solution()
    ans = {}
    for i in range(1, 9):
        ans[i] = s.generateParenthesis(i)
        print(len(ans[i]))
'''1
2
5
14
42
132
429
1430'''
