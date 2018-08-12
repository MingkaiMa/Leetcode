/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    
    bool hasCycle(ListNode *head) {
        if(head == nullptr)
            return false;
        
        if(head->next == nullptr)
            return false;
        
        if(head->next->next == nullptr)
        {
            return false;
        }
        
        ListNode* node1 = head->next;
        ListNode* node2 = head->next->next;
        
        while(node1 != nullptr && node2 != nullptr)
        {
            if(node1 == node2)
                return true;
            
            node1 = node1->next;
            node2 = node2->next;
            if(node2 == nullptr)
                return false;
            
            node2 = node2->next;
        }
        return false;
    }
    
    ListNode *detectCycle(ListNode *head) {
        
        if(hasCycle(head) == false)
            return nullptr;
        
        if(head == nullptr)
            return nullptr;
        
        if(head->next == nullptr)
            return nullptr;
        
        if(head->next->next == nullptr)
        {
            return nullptr;
        }
        
        ListNode* node1 = head->next;
        ListNode* node2 = head->next->next;
        
        while(node1 != nullptr && node2 != nullptr)
        {
            if(node1 == node2)
                break;
            
            node1 = node1->next;
            node2 = node2->next;
            if(node2 == nullptr || node1 == nullptr)
                return nullptr;
            
            node2 = node2->next;
        }
        
        
        ListNode* tempCurr = node1->next;
        int count = 1;
        while(tempCurr != node1)
        {
            count++;
            tempCurr = tempCurr->next;
        }
        
        ListNode* afterNode = head;
        int tempcount = count;
        while(tempcount > 0)
        {
            afterNode = afterNode->next;
            tempcount--;
        }
        
        ListNode* aheadNode = head;
        
        while(aheadNode != afterNode)
        {
            aheadNode = aheadNode->next;
            afterNode = afterNode->next;
        }
        
        return aheadNode;
    }
};
