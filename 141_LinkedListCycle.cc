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
};
