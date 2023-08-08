class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        tset=set()
        for i in nums:
            if i in tset:
                return True
            else:
                tset.add(i)
        return False