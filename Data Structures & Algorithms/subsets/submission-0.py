class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        path = []

        def dfs(start):
            if start == len(nums):
                # enumurate to the end
                result.append(path.copy())
                return
            
            # dfs without element start
            dfs(start+1)

            # dfs with element start
            path.append(nums[start])
            dfs(start+1)
            path.pop()
        
        dfs(0)
        return result

            
        