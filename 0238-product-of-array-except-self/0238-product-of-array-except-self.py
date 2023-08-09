class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        p=1
        count=0
        for i in nums:
            if i!=0:
                p=p*i
            else:
                count+=1
        ans=[]
        for i in nums:
            if count==0:
                val=p//i
                ans.append(p//i)
            elif count==1:
                if i!=0:
                    ans.append(0)
                else:
                    ans.append(p)
            elif count>1:
                ans.append(0)
        return ans
            
        
        