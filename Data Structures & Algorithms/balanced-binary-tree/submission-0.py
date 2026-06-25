# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
                
        def isBalancedAndReturnHeight(root) -> Tuple[bool, int]:
            if not root:
                return True, 0

            is_balanced_left, height_left = isBalancedAndReturnHeight(root.left)
            is_balanced_right, height_right = isBalancedAndReturnHeight(root.right)

            height = max(height_left, height_right) + 1
            is_balanced = is_balanced_left and is_balanced_right and abs(height_left - height_right) <= 1
            return is_balanced, height

        is_balanced, height = isBalancedAndReturnHeight(root)
        return is_balanced