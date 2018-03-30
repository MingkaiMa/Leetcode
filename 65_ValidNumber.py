class Solution:
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        import re
        p = re.compile("^\s*[\+\-]?(([0-9]+(e[\+\-]?[0-9]+)?)|(([0-9]+)?\.[0-9]+(e[\+\-]?[0-9]+)?)|([0-9]+\.([0-9]+)?(e[\+\-]?[0-9]+)?))\s*$")
        
        if re.match(p, s):
            return True
        return False
        
