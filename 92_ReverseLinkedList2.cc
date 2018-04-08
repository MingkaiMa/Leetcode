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
    
    

    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL)
            return NULL;
        
        if(m == n)
            return head;
        
        if(m > n)
            return head;
        
        
        int diff = n - m;
        
        ListNode* left = head;
        ListNode* right = head;
        
        
        ListNode* next_right = NULL;
        
        
        while(diff > 0  && right->next != NULL)
        {
            right = right->next;
            diff--;
        }
        
        
        if(m == 1)
        {

            next_right = right->next;
            
            //cout << next_right->val << "\n";
            
            ListNode* curr = left;
            ListNode* next_node = curr->next;
            //ListNode* reserve_next_node = next_node->next;
            
            while(1)
            {
                ListNode* reserve_next_node = next_node->next;
                next_node->next = curr;
                curr = next_node;
                next_node = reserve_next_node;
                
                if(next_node == next_right)
                    break;
            }
            
            
            head = curr;
            
            left->next = next_right;
            
            return head;
        }
        
        int i = 2;
        
        
        
        while(i < m && left->next != NULL && right->next != NULL)
        {
            left = left->next;
            right = right->next;
            i++;
        }
        
        
        ListNode* before_left = left;
        ListNode* tail = left->next;
        
        next_right = right->next->next;
        
        ListNode* curr2 = tail;
        ListNode* next_node = curr2->next;
        
        while(1)
        {
            ListNode* reserveNode = next_node->next;
            next_node->next = curr2;
            curr2 = next_node;
            next_node = reserveNode;
            
            if(next_node == next_right)
                break;
        }
        
        before_left->next = curr2;
        
        tail->next = next_right;
        
        return head;
        
        
        
    }
};
