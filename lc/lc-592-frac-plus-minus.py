class Solution:
    def gcd(self, a, b):
        return self.gcd(b, a % b) if b != 0 else a

    def lcm(self, a, b):
        return a * b // self.gcd(a, b)

    def fractionAddition(self, expression: str) -> str:
        num, symb = [], []
        tmp = ''
        for i in expression + '+':
            if i == '-' or i == '+':
                symb.append(i)
                if tmp != '':
                    num.append(tmp)
                    tmp = ''
            else:
                tmp += i
        symb = symb[:-1]
        denomintor = eval(num[0].split('/')[-1])
        n, d = num[0].split('/')
        n, d = [n], [d]
        for j in range(1, len(num)):
            tn, td = num[j].split('/')  # tn:str, td:str
            n.append(tn)
            d.append(td)
            denomintor = self.lcm(denomintor, eval(td))
        numerator = 0
        # print(f"n={n},d={d}")
        if (Sn := len(num)) != len(symb):
            symb.insert(0, '+')
        for i in range(Sn):
            numerator += eval(symb[i] + n[i] + '*' + str(
                denomintor // eval(d[i])))
        ans = str(numerator) + '/' + str(denomintor)
        # print(f"ans={ans}")
        if ans[0] == '0':
            return '0/1'
        p, q = ans.split('/')
        p, q = eval(p), eval(q)
        gcdpq = self.gcd(p, q)
        if self.gcd(p, q) != 1:
            return str(p // gcdpq) + '/' + str(q // gcdpq)
        else:
            return ans


if __name__ == '__main__':
    s = Solution()
    test1 = ["3/10+1/5-10/7-5/6-2/5", "-1/2+1/2+1/3", '-1/2+1/2']
    test2 = ['1/2-1/3', "5/3+1/3", '3/5', '3/1']
    for i in test1 + test2:
        ans = s.fractionAddition(i)
        print(ans)

    # def gcd(a, b):
    #     return gcd(b, a % b) if b != 0 else a

    # def lcm(a, b):
    #     return a * b // gcd(a, b)
