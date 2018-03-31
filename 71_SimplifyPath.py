class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        pathList = path.split('/')
        
        L = []
        for p in pathList:
            if p == '.':
                continue
            
            if p == '..':
                if(len(L) > 0):
                    L.pop()
            
            elif len(p) > 0:
                L.append(p)

        L = [i for i in L if i]

        
        if(len(L) == 1):
            s = '/'
            s += L[0]
            return s;
        
        s = ''
        for i in range(len(L)):
            s += '/'
            s += L[i]

        if not s:
            return '/'
        else:
            return s
            
