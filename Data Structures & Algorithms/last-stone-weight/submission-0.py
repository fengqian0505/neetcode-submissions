class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = [-stone for stone in stones]
        heapq.heapify(heap)

        while len(heap) > 1:
            weight_one = -heapq.heappop(heap)
            weight_two = -heapq.heappop(heap)
            new_weight = abs(weight_one - weight_two)
            heapq.heappush(heap, -new_weight)

        if len(heap) == 0:
            return 0
        else:
            return -heap[0]


        