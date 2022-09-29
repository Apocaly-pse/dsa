from typing import List
from collections import deque


class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        if (n := len(grid)) == 1:
            return -1
        visited = [[0] * n for _ in range(n)]
        que = deque()
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    que.append((i, j))
                    visited[i][j] = 1
        dir1 = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        step = 0
        maxstep = 0
        while que:
            for _ in range(len(que)):
                x, y = que.popleft()
                if grid[x][y] == 0:
                    maxstep = max(maxstep, step)
                for dx, dy in dir1:
                    nx, ny = x + dx, y + dy
                    if nx < 0 or nx >= n or \
                        ny < 0 or ny >= n or \
                            visited[nx][ny] == 1:
                        continue
                    visited[nx][ny] = 1
                    que.append((nx, ny))
            step += 1

        return maxstep if maxstep else -1


if __name__ == '__main__':
    s = Solution().maxDistance
    print(s([[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]))#-1
    print(s([[1, 0, 1], [0, 0, 0], [1, 0, 1]]))  # 2
    print(s([[1, 0, 0], [0, 0, 0], [0, 0, 0]]))  # 4
