class Solution:
    def convert(self, s: str, n: int) -> str:
        if n == 1:
            return s

        p = [''] * n
        r = 0
        d = 1

        for ch in s:
            p[r] += ch
            if r == 0:
                d = 1
            elif r == n - 1:
                d = -1
            r += d

        return ''.join(p)