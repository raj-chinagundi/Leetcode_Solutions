class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        s=0
        count=0
        while s<len(nums):
            if nums[s]==0:
                nums.pop(s)
                count+=1
                continue
            s+=1
        z=[0]*count
        nums.extend(z)
        
        
        