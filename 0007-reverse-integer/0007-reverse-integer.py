class Solution:
    def reverse(self, x: int) -> int:
        ans = 0
        while x:
            d = int(x % 10) if x > 0 else -int(-x % 10)
            x = int(x / 10)
            if ans > 214748364 or (ans == 214748364 and d > 7):
                return 0
            if ans < -214748364 or (ans == -214748364 and d < -8):
                return 0
            ans = ans * 10 + d
        return ans
