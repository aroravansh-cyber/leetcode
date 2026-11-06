class Solution:
    def countServers(self, n, logs, x, queries):
        logs.sort(key=lambda a: a[1])
        q = sorted(enumerate(queries), key=lambda a: a[1])
        count = {}
        ans = [0] * len(queries)
        left = right = 0
        for idx, time in q:
            while right < len(logs) and logs[right][1] <= time:
                s = logs[right][0]
                count[s] = count.get(s, 0) + 1
                right += 1
            while left < right and logs[left][1] < time - x:
                s = logs[left][0]
                count[s] -= 1
                if count[s] == 0:
                    del count[s]
                left += 1
            ans[idx] = n - len(count)
        return ans