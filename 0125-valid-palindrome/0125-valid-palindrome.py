class Solution:
    def isPalindrome(self, s: str) -> bool:
        s.replace(" ", "")
        news=""
        for i in s:
            if i.isalnum():
                news+=i
        if news.lower()==news[::-1].lower():
            return True
            
        