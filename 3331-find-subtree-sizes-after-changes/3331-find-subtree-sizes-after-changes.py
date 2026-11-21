class Solution:
    def findSubtreeSizes(self, parent, s):
        n = len(parent)
        adj = [[] for _ in range(n)]
        for i in range(1, n):
            adj[parent[i]].append(i)
        last = {}
        new_parent = parent[:]
        def dfs(node):
            char = s[node]
            old = last.get(char, -1)
            if old != -1:
                new_parent[node] = old
            last[char] = node
            for child in adj[node]:
                dfs(child)
            if old == -1:
                last.pop(char)
            else:
                last[char] = old
        dfs(0)
        adj = [[] for _ in range(n)]
        for i in range(1, n):
            adj[new_parent[i]].append(i)
        answer = [1] * n
        def calculate(node):
            for child in adj[node]:
                calculate(child)
                answer[node] += answer[child]

        calculate(0)
        return answer