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
    
    ListNode* getLastNode(ListNode* startNode)
    {
        ListNode* curr = startNode;
        

        while(curr->next->next != nullptr)
            curr = curr->next;
        
        ListNode* lastNode = curr->next;
        curr->next = nullptr;
        return lastNode;
        
    }
    
    
    void reorderList(ListNode* head) {
        if(head == nullptr)
            return;
        
        if(head->next == nullptr)
            return;
        
        if(head->next->next == nullptr)
            return;
        
        ListNode* currNode = head;
        
        while(true)
        {
            ListNode* reverseNextNode = currNode->next;
            ListNode* lastNode = getLastNode(currNode);
            currNode->next = lastNode;
            lastNode->next = reverseNextNode;
            
            currNode = reverseNextNode;
            
            if(reverseNextNode->next == nullptr)
                break;
            
            if(reverseNextNode->next->next == nullptr)
                break;
        }
        return;
    }
};
