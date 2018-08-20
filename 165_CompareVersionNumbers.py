class Solution:
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        
 
        lst1 = version1.split('.')
        lst2 = version2.split('.')
        
        list1 = [int(i) for i in lst1]
        list2 = [int(i) for i in lst2]
        
        i = 0
        j = 0
        
        while(i < len(list1) and j < len(list2)):
            if(list1[i] > list2[j]):
                return 1
            
            if(list1[i] < list2[j]):
                return -1
            i += 1
            j += 1
        
        

        if i == len(list1) and j != len(list2):
            if all(ii == 0 for ii in list2[j: ]):
                return 0
            
            return -1
        
        if i != len(list1) and j == len(list2):
            if all(ii == 0 for ii in list1[i: ]):
                return 0
            
            return 1
        
        return 0
