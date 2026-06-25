# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        diameter, depth = self.diameterAndDepthOfBinaryTree(root)
        return diameter

    def diameterAndDepthOfBinaryTree(self, root: Optional[TreeNode]) -> Tuple[int, int]:
        if not root:
            return 0, 0

        diameter_left, depth_left = self.diameterAndDepthOfBinaryTree(root.left)
        diameter_right, depth_right = self.diameterAndDepthOfBinaryTree(root.right)

        diameter = max(depth_left + depth_right, diameter_left, diameter_right)
        return diameter, max(depth_left, depth_right) + 1
