class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        both = min(need1, need2)
        a = cost1 * need1 + cost2 * need2
        b = costBoth * both + cost1 * (need1 - both) + cost2 * (need2 - both)
        c = costBoth * max(need1, need2)
        return min(a, b, c)