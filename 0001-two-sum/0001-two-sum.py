class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d={}
        for i in range(len(nums)):
            tempd={nums[i]:i}
            d.update(tempd)
        # print(d)
        for i in range(len(nums)):
            search=target-nums[i]
            # print(search)
            if search in d and i!=d[search]:
                return [i,d[search]]
        return []
                