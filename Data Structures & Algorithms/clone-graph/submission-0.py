"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return node

        node_dict = {}

        def dfs(curr):
            if not curr:
                return curr

            # if this node already cloned, return the cloned one directly instead of cloning it again.
            if curr in node_dict:
                return node_dict[curr]

            # copy the node
            copy = Node(curr.val)

            node_dict[curr] = copy            
            
            # copy it's neighbors
            for neighbor in curr.neighbors:
                copy.neighbors.append(dfs(neighbor))

            # return the cloned node which also has it's neighbours
            return copy

        return dfs(node)
        