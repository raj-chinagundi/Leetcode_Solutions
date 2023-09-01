class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet=set(nums)
        longest=0
        
        for n in nums:
            if (n-1) not in numSet:
                curr_len=0
                while n+curr_len in numSet:
                    curr_len+=1
                    
                longest=max(longest,curr_len)
        
        return longest
                