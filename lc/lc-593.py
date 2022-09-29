from typing import List


class Solution:
    def validSquare(self, p1: List[int], p2: List[int],
                    p3: List[int], p4: List[int]) -> bool:
        def dist(pa, pb):
            return (pa[0] - pb[0])**2 + (pa[1] - pb[1])**2
        d12 = dist(p1, p2)
        d13 = dist(p1, p3)
        d14 = dist(p1, p4)
        d23 = dist(p3, p2)
        d24 = dist(p4, p2)
        d34 = dist(p3, p4)
        d = set([d12, d13, d14, d23, d24, d34])
        if len(d) != 2 or 0 in d:
            return False
        return True


if __name__ == '__main__':
    s = Solution()
    ans = s.validSquare([0, 0], [0, 1], [1, 0], [1, 10])
    print(ans)
    ans = s.validSquare([0, 0], [1, 0], [0, 1], [1, 1])
    print(ans)
    ans = s.validSquare([0, 0], [1, 1], [1, 0], [0, 1])
    print(ans)
    ans = s.validSquare([1, 0], [-1, 0], [0, 1], [0, -1])
    print(ans)
