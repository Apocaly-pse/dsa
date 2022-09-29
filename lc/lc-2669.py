from typing import List


class Solution:
    def cutSquares(self, square1: List[int], square2: List[int]) \
            -> List[float]:
        x1, y1, a1 = square1[0], square1[1], square1[-1]
        x2, y2, a2 = square2[0], square2[1], square2[-1]
        c1x, c1y = x1 + a1 / 2, y1 + a1 / 2
        c2x, c2y = x2 + a2 / 2, y2 + a2 / 2
        miny = y1 if y1 < y2 else y2
        maxy = y1 + a1 if y1 + a1 > y2 + a2 else y2 + a2
        minx = x1 if x1 < x2 else x2
        maxx = x1 + a1 if x1 + a1 > x2 + a2 else x2 + a2
        # 中心连线平行y, 返回斜率最大即平行于y轴直线
        if c1x == c2x:
            return [c1x, miny, c1x, maxy]
        def elly(x):
            return c2y + (c2y - c1y) / (c2x - c1x) * (x - c2x)
        def ellx(y):
            return (y - c2y) * (c2x - c1x) / (c2y - c1y) + c2x
        if c1y == c2y:
            return [minx, elly(minx), maxx, elly(maxx)]
        else:
            if ellx(maxy)<ellx(miny):
                return [ellx(maxy), maxy, ellx(miny), miny] if ellx(maxy)>minx else [minx, elly(minx), maxx, elly(maxx)]
            else:
                return [ellx(miny), miny, ellx(maxy), maxy] if ellx(miny)>minx else [minx, elly(minx), maxx, elly(maxx)]


s = Solution()
print(s.cutSquares([68,130,64], [-230,194,7]))
print(s.cutSquares([-1, 1, 3], [0, 0, 5]))
print(s.cutSquares([-1, 1, 3], [-1, 1, 3]))
print(s.cutSquares([-1, 1, 2], [0, -1, 2]))

'''
[-230.0,197.88055,132.0,158.52067]
[-1,1,3]
[0,0,5]
[-1,1,3]
[-1,1,3]
[-1,1,2]
[0,-1,2]




'''
