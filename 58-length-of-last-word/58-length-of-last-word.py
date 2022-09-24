class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words = s.split(' ')
        idx = len(words) - 1
        
        while idx >= 0 and (words[idx] == "" or " " in words):
            idx -= 1
            
        return len(words[idx])