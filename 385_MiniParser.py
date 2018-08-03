# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """
import re

class Solution:
    def deserialize(self, s):
        """
        :type s: str
        :rtype: NestedInteger
        """
        
        L = re.findall(r'(\-?\d+|\[|\])', s)
        stack = []
        for token in L:
            if token == '[':
                stack.append(token)
            
            elif re.match(r'^\-?\d+$', token):
                stack.append(int(token))
            
            elif token == ']':
                alist = NestedInteger()
                saveList = []
                while(len(stack)):
                    element = stack.pop()
                    if element != '[':
                        if isinstance(element, int):
                            a = NestedInteger(element)
                            saveList.append(a)
                        else:
                            saveList.append(element)
                    else:
                        break
                
                saveList.reverse()
                for i in saveList:
                    alist.add(i)
                
                stack.append(alist)
        
        res = stack.pop()
        return res
                
                
                
                    
