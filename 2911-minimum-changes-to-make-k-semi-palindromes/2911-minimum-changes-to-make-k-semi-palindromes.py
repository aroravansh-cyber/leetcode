class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        n = len(s)
        INF = float('inf')

        divisors = [[] for _ in range(n + 1)]
        for L in range(2, n + 1):
            for d in range(1, L):
                if L % d == 0:
                    divisors[L].append(d)

        cost = [[INF] * n for _ in range(n)]
        for i in range(n):
            for j in range(i + 1, n):
                L = j - i + 1
                best = INF
                for d in divisors[L]:
                    changes = 0
                    m = L // d
                    for r in range(d):
                        lo, hi = 0, m - 1
                        while lo < hi:
                            if s[i + r + lo * d] != s[i + r + hi * d]:
                                changes += 1
                            lo += 1
                            hi -= 1
                    best = min(best, changes)
                cost[i][j] = best

        dp = [[INF] * (n + 1) for _ in range(k + 1)]
        dp[0][0] = 0
        for j in range(1, k + 1):
            for i in range(2 * j, n + 1):
                for p in range(2 * (j - 1), i - 1):
                    if dp[j - 1][p] != INF and cost[p][i - 1] != INF:
                        dp[j][i] = min(dp[j][i], dp[j - 1][p] + cost[p][i - 1])

        return dp[k][n]