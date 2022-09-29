class Solution:
    def solveEquation(self, equation: str) -> str:
        # 1. 移项
        # 2. 合并同类项
        # 3. 整理
        if equation[0] != '-':
            equation = '+' + equation
        equation += '#'
        symbL, symbR, valL, valR = [], [], [], []
        flag = 0  # left
        isRightFirst = 0
        pm = {'+', '-'}
        tmp = ''
        for s_ in equation:
            if flag == 0:  # left
                if s_ != '=':
                    if s_ in pm:
                        symbL.append(s_)
                        if tmp:
                            valL.append(tmp)
                            tmp = ''
                    else:  # x,num
                        tmp += s_
                else:  # i='=',进入右边的式子
                    flag = 1
                    valL.append(tmp)
                    tmp = ''
            else:  # right
                if isRightFirst == 0:
                    if s_ != '-':
                        symbR.append('+')
                        tmp += s_
                    else:
                        symbR.append('-')
                    isRightFirst = 1
                    continue  # 判断完第一个字符之后必须跳出
                if s_ in pm:
                    symbR.append(s_)
                    if tmp:
                        valR.append(tmp)
                        tmp = ''
                elif s_ == '#':  # 结尾
                    valR.append(tmp)
                else:  # x,num
                    tmp += s_

        def getCoeff(symb1, val1):
            cx, nu = 0, 0
            for i in range(len(symb1)):
                val = val1[i]
                if 'x' in val:
                    if val == 'x':
                        cx += -1 if symb1[i] == '-' else 1
                    else:  # x系数不为1
                        cx += int(symb1[i] + val[:-1]
                                  ) if symb1[i] == '-' else int(val[:-1])
                else:  # num
                    nu += int('-' + val) if symb1[i] == '-' else int(val)
            return cx, nu

        # return symbL, valL, symbR, valR
        # return xL, numL, xR, numR

        xL, numL = getCoeff(symbL, valL)
        xR, numR = getCoeff(symbR, valR)

        coX, Nu = xL - xR, numR - numL
        if coX == 0:
            return 'Infinite solutions' if Nu == 0 else 'No solution'
        else:
            return 'x=' + str(Nu // coX)


if __name__ == '__main__':
    s = Solution()
    print(s.solveEquation("-x=-14"))  # x=14
    print(s.solveEquation("x+5-3+x=6+x-2"))  # x=2
    print(s.solveEquation("-x=-x+23x-1+x-23"))  # x=14
    print(s.solveEquation("x+5-3+x=6+x-2"))  # x=2
    print(s.solveEquation("x+1=x"))  # "No solution"
    print(s.solveEquation("x-1=0"))  # x=1
    print(s.solveEquation("x=x"))  # "Infinite solutions"
    print(s.solveEquation("x+12=2x"))  # x=12
