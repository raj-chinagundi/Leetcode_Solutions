def split_sort(word):
    l=list(word)
    l.sort()
    s="".join(l)
    return s

class Solution:        
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        word_list={}
        ans=[]
        for i in strs:
            w=split_sort(i)
            if w in word_list:
                word_list[w].append(i)
            else:
                word_list[w]=list()
                word_list[w].append(i)
        for v in word_list.values():
            ans.append(v)
        
        return ans