class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashmap={}
        for i in nums:
            if i not in hashmap:
                hashmap[i]=1;
            else:
                hashmap[i]+=1

        sorted_dict = list(reversed(sorted([(value, key) for (key, value) in hashmap.items()])))
        
        ans=[]
        for i in range(k):
            ans.append(sorted_dict[i][1])
            
        return ans