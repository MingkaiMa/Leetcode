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
    ListNode* rotateRight(ListNode* head, int k) {
        
 
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        

        
        int length = 0;
        ListNode* countNode = head;
        
        while(countNode != NULL)
        {
            length += 1;
            countNode = countNode->next;
        }

        k = k % length;
        
        

        
        
        ListNode* p1 = head;
        ListNode* p2 = head;
        
        
        while(k > 0)
        {
            k--;
            if(p2->next != NULL)
                p2 = p2->next;
            else
                p2 = head;      
        }
        
        if(p1 == p2)
        {
            return head;
        }
        
        while(p1->next != NULL && p2->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        p2->next = head;
        head = p1->next;
        p1->next = NULL;
        
        return head;
    }
};
