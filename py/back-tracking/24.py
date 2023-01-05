from typing import List


class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:

        def calc(i, lhs, rhs):
            match i:
                case 0:
                    return lhs + rhs
                case 1:
                    return lhs - rhs
                case 2:
                    return rhs - lhs
                case 3:
                    return lhs * rhs
                case 4:  # 判断被除数不为零
                    return rhs and lhs / rhs
                case 5:
                    return lhs and rhs / lhs
                case _:  # 合并两个数
                    return lhs * 10 + rhs
        ops = ['+', '-', '-', '*', '/', '/', '']
        expr = ''

        def bt(tmp):
            nonlocal expr
            if (n := len(tmp)) == 1:
                print(expr)
                return abs(24 - tmp[0]) < 1e-4
            for i in range(n - 1):  # 遍历左操作数
                for j in range(i + 1, n):  # 遍历右操作数
                    restmp = []  # 剩余的数
                    for k in range(n):
                        if k == j or k == i:
                            continue
                        # 如果两个数未被取过, 添加到剩余的数列表中
                        restmp.append(tmp[k])
                    expr = f"({tmp[i]}"
                    for p in range(6):  # 遍历操作符
                        # 计算中间结果并存入剩余的数列表等待下一次计算
                        restmp.append(calc(p, tmp[i], tmp[j]))
                        t1 = f"{ops[p]}{tmp[j]})"
                        expr += t1
                        # print(expr)
                        # 如果回溯结果为真返回
                        if bt(restmp):
                            return True
                        # 去掉中间结果, 找新的两个数计算
                        restmp.pop()
                        # expr = expr[len(t1) + 2:]
            return False
        return bt(cards)


if __name__ == '__main__':
    s = Solution().judgePoint24
    # print(s([1, 2, 1, 2]))
    print(s([4, 1, 8, 7]))
