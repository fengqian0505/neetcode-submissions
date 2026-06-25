class UnionFind:
    def __init__(self):
        self.parents = {}

    def find(self, v: int) -> int:
        # Lazy initialization + path compression
        if v not in self.parents:
            self.parents[v] = v
        if self.parents[v] != v:
            self.parents[v] = self.find(self.parents[v])
        return self.parents[v]

    def union(self, v1: int, v2: int) -> bool:
        root1, root2 = self.find(v1), self.find(v2)
        if root1 == root2:
            return False  # already connected → cycle
        self.parents[root2] = root1  # attach roots
        return True

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        uf = UnionFind()
        for v1, v2 in edges:
            if not uf.union(v1, v2):
                # find Cycle
                return [v1, v2]