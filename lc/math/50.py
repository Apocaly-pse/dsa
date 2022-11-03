class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n==0:return 1
        elif n==1:return x
        if n&1:#odd
            return self.myPow(x, n//2)**2*x
        else:
            return self.myPow(x, n//2)**2


if __name__ == "__main__":
    s=Solution().myPow
    print(s(2.0,10))
    print(s(0.001,2**31))
