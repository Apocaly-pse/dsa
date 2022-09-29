class Solution:
    def convert_v1(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        ans = [''] * numRows
        L = numRows + numRows - 2
        for i in range(len(s)):
            if i % L == 0:
                ans[0] += s[i]
                continue

            for j in range(1, numRows - 1):
                if i % L == j or i % L == L - j:
                    ans[j] += s[i]
                    break

            if i % L == numRows - 1:
                ans[numRows - 1] += s[i]
                continue
        return "".join(ans)

    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        ans = [''] * numRows
        L = numRows + numRows - 2
        for i in range(len(s)):
            if i % L == 0:
                ans[0] += s[i]
                continue
            if i % L == numRows - 1:
                ans[numRows - 1] += s[i]
                continue
            for j in range(1, numRows - 1):
                if i % L == j or i % L == L - j:
                    ans[j] += s[i]
                    break

        return "".join(ans)


if __name__ == '__main__':
    s1 = Solution().convert
    print(s1(s="PAYPALISHIRING", numRows=3))
    print(s1(s="PAYPALISHIRING", numRows=4))
    print(s1(s="PAYPALISHIRING", numRows=5))
    print(s1(s="AVDVDRVF", numRows=1))
