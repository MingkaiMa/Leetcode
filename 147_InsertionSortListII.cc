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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr)
            return head;
        
        if(head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(0);
        ListNode* p = head;
        
        dummy->next = head;
        
        while(p->next != nullptr)
        {
            if(p->val < p->next->val)
                p = p->next;
            else
            {
                ListNode* temp = p->next;
                ListNode* q = dummy;
                p->next = p->next->next;
                
                while(q->next->val < temp->val)
                    q = q->next;
                
                temp->next = q->next;
                q->next = temp;
            }
        }
        return dummy->next;
        
    }
};
