class Solution:
    def fillCups(self, amount: List[int]) -> int:
        cnt = 0
        while sum(amount) > 0:
            amount = sorted(amount, reverse=True)
            if amount[0] > 0 and amount[1] > 0:
                cnt += 1
                amount[0] -= 1
                amount[1] -= 1
            else:
                return cnt + max(amount)
