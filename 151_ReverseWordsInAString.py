class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        L = s.split()
        
        L = L[::-1]
        
        return ' '.join(L)
        
