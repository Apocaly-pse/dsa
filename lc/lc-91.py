class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == '0':
            return 0
        n = len(s)
        a, b, c = 0, 1, 0
        for i in range(1, n):
            if s[i] == '0':
                if s[i - 1] == '1' or s[i - 1] == '2':
                    c = b
                    if i > 1 and b > a:  # 110->121
                        c = a
                else:  # 190->120
                    return 0
            else:
                if s[i - 1] == '0':  # 101->111
                    c = b
                else:  # 12->12
                    if int(s[i - 1:i + 1]) < 27:  # 123->123
                        c = b + 1
                        if i > 1:
                            c += a - 1
                    else:  # 129->122
                        c = b
            a, b = b, c
        return b


if __name__ == '__main__':
    s = Solution()
    test_eg = ["1", '1123', '129', '190', '1010', '10',
               '1109', '10120', "11106", "2611055971756562"]
    for i in test_eg:
        ans = s.numDecodings(i)
        print(ans)
