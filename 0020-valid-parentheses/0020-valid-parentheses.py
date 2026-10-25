class Solution:
    def isValid(self, s: str) -> bool:
        lisss = []
        for c in s:
            if c == '(' or c == '{' or c == '[':
                lisss.append(c)
            else:
                if len(lisss) == 0:
                    return False
                last = lisss.pop()
                if c == ')' and last != '(':
                    return False
                if c == '}' and last != '{':
                    return False
                if c == ']' and last != '[':
                    return False
        return len(lisss) == 0