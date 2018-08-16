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
    
    

    ListNode* mergeTwoLists(ListNode* ahead, ListNode* behind)
    {
        ListNode dummy(-1);
        for(ListNode* p = &dummy; ahead != nullptr || behind != nullptr; p = p->next)
        {
            int val1 = ahead == nullptr ? INT_MAX : ahead->val;
            int val2 = behind == nullptr ? INT_MAX : behind->val;
            
            if(val1 <= val2)
            {
                p->next = ahead;
                ahead = ahead->next;
            }
            else
            {
                p->next = behind;
                behind = behind->next;
            }
        }
        
        return dummy.next;
    }
    
    
    
    
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        
        ListNode* pt1 = head;
        ListNode* pt2 = head;
        
        while(pt2->next != nullptr && pt2->next->next != nullptr)
        {
            pt1 = pt1->next;
            pt2 = pt2->next->next;
        }
        
        pt2 = pt1;
        pt1 = pt1->next;
        pt2->next = nullptr;
        
        ListNode* ahead = sortList(head);
        ListNode* behind = sortList(pt1);
        
        return mergeTwoLists(ahead, behind); 
    }
};
