from typing import List
from itertools import accumulate
from string import ascii_lowercase


class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        shift = [0] * (len(s) + 1)
        # 构造差分数组
        for start, end, di in shifts:
            shift[start] += 2 * di - 1
            shift[end + 1] -= 2 * di - 1

        ans = ''
        for c, sft in zip(s, accumulate(shift)):
            ans += chr((ord(c) + sft - 97) % 26 + 97)
        return ans


if __name__ == '__main__':
    s = Solution().shiftingLetters
    print(s('abc', [[0, 1, 0], [1, 2, 1], [0, 2, 1]]))
