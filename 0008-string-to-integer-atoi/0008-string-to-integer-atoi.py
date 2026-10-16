class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        if not s:
            return 0

        sign = 1
        if s[0] in '+-':
            if s[0] == '-':
                sign = -1
            s = s[1:]

        num = 0
        for ch in s:
            if not ch.isdigit():
                break
            num = num * 10 + ord(ch) - 48

        num *= sign
        return max(-2**31, min(2**31 - 1, num))