import queue
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        pq=queue.PriorityQueue()
        for i in nums:
            pq.put(i*-1)
        
        while k!=0:
            top=pq.get()
            k-=1
        
        return top*-1