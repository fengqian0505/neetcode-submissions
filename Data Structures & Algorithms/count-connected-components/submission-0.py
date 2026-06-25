class UnionFind:
    def __init__(self, n):
        self.parents = [node for node in range(n)]
        self.count = n

    def find(self, v: int) -> int:
        #  path compression
        if self.parents[v] != v:
            self.parents[v] = self.find(self.parents[v])
        return self.parents[v]

    def union(self, v1: int, v2: int):
        root1, root2 = self.find(v1), self.find(v2)
        if root1 == root2:
            return
        self.parents[root2] = root1  # attach roots
        self.count -= 1

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        uf = UnionFind(n)
        for v1, v2 in edges:
            uf.union(v1, v2)
        return uf.count

        