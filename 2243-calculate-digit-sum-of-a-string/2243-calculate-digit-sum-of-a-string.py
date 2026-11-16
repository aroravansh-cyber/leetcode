class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            new_string = ""
            for i in range(0, len(s), k):
                group = s[i:i+k]
                total = 0
                for ch in group:
                    total += int(ch)
                new_string += str(total)
            s = new_string
        return s