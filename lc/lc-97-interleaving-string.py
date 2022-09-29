'''class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if (l1 := len(s1)) + (l2 := len(s2)) != len(s3):
            return False
        if s1 == s2 == s3 == '' or s1 + s2 == s3:
            return True
        if s1 == '' or s2 == '':
            return True if s1 + s2 == s3 else False
        # ================ init begin ========================== #
        dp = [[False] * (l2 + 1) for _ in range(l1 + 1)]
        dp[0][0] = True
        for i in range(1, l2 + 1):
            if not dp[0][i - 1]:
                break
            if s2[i - 1] == s3[i - 1]:
                dp[0][i] = True
        for i in range(1, l1 + 1):
            if not dp[i - 1][0]:
                break
            if s1[i - 1] == s3[i - 1]:
                dp[i][0] = True
        # if not dp[0][1] and not dp[1][0]:
        #     return False
        # ================ init end ========================== #
        for i in range(1, l1 + 1):
            for j in range(1, l2 + 1):
                if dp[i][j - 1]:
                    dp[i][j] = s2[j - 1] == s3[i + j - 1]
                if dp[i - 1][j]:
                    dp[i][j] = s1[i - 1] == s3[i + j - 1]
        return dp[-1][-1]'''


class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if (l1 := len(s1)) + (l2 := len(s2)) != len(s3):
            return False
        if s1 == s2 == s3 == '' or s1 + s2 == s3:
            return True
        if s1 == '' or s2 == '':
            return True if s1 + s2 == s3 else False
        # ================ init begin ========================== #
        dp = [True] + [False] * l2
        for i in range(1, l2 + 1):
            if not dp[i - 1]:
                break
            if s2[i - 1] == s3[i - 1]:
                dp[i] = True
        if not dp[0] and not dp[1]:
            return False
        # ================== init end ========================== #
        for i in range(l1 + 1):
            for j in range(l2 + 1):
                if i > 0:
                    # 这一步`&=`判断已经包含了上边的值
                    dp[j] &= (s1[i - 1] == s3[i + j - 1])
                if j > 0:
                    # dp[j-1]代表判断左边的值
                    # 这一步`|=`是必要的, 由于上一个判断已经写入了dp[j],
                    # 如果上一步为True,当前值就算不满足左边的值成立,也有上边的值成立这一条件,
                    # 就需要用'或'
                    dp[j] = (dp[j - 1] and s2[j - 1] == s3[i + j - 1])
            # print(dp)
        return dp[-1]


if __name__ == '__main__':
    s = Solution()
    ans = s.isInterleave(s1="aabcc", s2="dbbca", s3="aadbbcbcac")
    print(ans)
    ans = s.isInterleave(s1="abc", s2="abc", s3="aabbcc")
    print(ans)
    ans = s.isInterleave(s1="aabcc", s2="dbbca", s3="aadbbbaccc")
    print(ans)
    ans = s.isInterleave("a", "c", "ca")
    print(ans)
