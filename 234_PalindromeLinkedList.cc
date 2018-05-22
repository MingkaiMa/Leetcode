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
    
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return head;
        
        if(head->next == nullptr)
            return head;
        
        if(head->next->next == nullptr)
        {
            ListNode* newHead = head->next;
            newHead->next = head;
            head->next = nullptr;
            head = newHead;
            return head;
        }
        
        ListNode* preNode = head;
        ListNode* curr = head->next;
        
        
        preNode->next = nullptr;
        
        while(true)
        {
            ListNode* nextNode = curr->next;
            curr->next = preNode;
            preNode = curr;
            if(nextNode == nullptr)
                break;
            curr = nextNode;
            
        }
        
        
        head = curr;
        return head;
        
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return true;
        
        // reverse the second half
        
        int length = 0;
        
        ListNode* curr = head;
        while(curr != nullptr)
        {
            length++;
            curr = curr->next;
            
        }
                
        int secondStart = 0;
        
        if(length & 1)
        {
            secondStart = length - length / 2 + 1;
        }
        else
            secondStart = length / 2 + 1;

        curr = head;
        while(secondStart > 1)
        {
            curr = curr->next;
            secondStart--;
        }
        
        cout << curr->val << endl;
        
        ListNode* newHead = reverseList(curr);
        
        
        ListNode* node1 = head;
        ListNode* node2 = newHead;
        while(node2 != nullptr)
        {
            if(node1->val != node2->val)
                return false;
            
            node1 = node1->next;
            node2 = node2->next;
        }
        
        return true;
        
    }
};
