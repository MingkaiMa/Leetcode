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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        if(head->next == NULL)
            return head;
        
        ListNode* p1 = head;
        
        while(p1 != NULL)
        {
            if(p1->next != NULL && p1->next->val == p1->val)
            {
                ListNode *p2 = p1;
                while(p2->next != NULL && p2->next->val == p2->val)
                    p2 = p2->next;
                
                p2 = p2->next;
                p1->next = p2;
                p1 = p2;
            }
            else
                p1 = p1->next;
        }
        
        return head;
        
    }
};
