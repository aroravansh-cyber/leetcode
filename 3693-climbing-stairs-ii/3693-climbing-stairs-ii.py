
class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        a = [float('inf')] * (n + 1)
        a[0] = 0
        for i in range(1, n + 1):
            for j in range(1, 4):
                if i >= j:
                    a[i] = min(a[i], a[i-j] + costs[i-1] + j*j)
        return a[n]
