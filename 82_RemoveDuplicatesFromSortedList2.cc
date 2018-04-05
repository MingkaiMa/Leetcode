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
         
        ListNode* currHead = head;
        int headflag = 0;
        
        if(head->next->val == head->val)
        {
            
            
            while(1)
            {
                while(currHead->next != NULL && currHead->next->val == currHead->val)
                    currHead = currHead->next;

                
                if(currHead == NULL)
                    break;


                if(currHead->next == NULL)
                {
                    headflag = 1;
                    break;
                }
                currHead = currHead->next;
                
                if(currHead->next == NULL)
                    break;

                if(currHead->next != NULL && currHead->next->val != currHead->val)
                    break;
            }
        }
        
        //cout << headflag << "\n";
        if(headflag == 1)
            head = currHead->next;
        else
            head = currHead;
        

        if(head == NULL || head->next == NULL)
            return head;
        
        // return head;
        
        
        ListNode* p1 = head;
        
        
        ListNode* p2 = p1->next;
        
        int flag = 0;
        
        while(p2 != NULL)
        {
            if(p2->next == NULL)
                break;
            
            if(p2->next->val != p2->val)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            else{
            
                while(true)
                {
                    while(p2->next != NULL && p2->next->val == p2->val)
                        p2 = p2->next;
                    
                    
                    
                    if(p2 == NULL)
                        break;
                    
                    if(p2->next == NULL)
                    {
                        flag = 1;
                        break;
                    }
                    
                    p2 = p2->next;
                    
                    if(p2->next == NULL)
                        break;
                    
                    
                    if(p2->next != NULL && p2->next->val != p2->val)
                        break;
                }
                
            }
            
            if(flag == 1)
                p1->next = p2->next;
            
            else
                p1->next = p2;
            
            if(p2 == NULL || p2->next == NULL)
                break;
            
        }
        
        return head;
        
    }
};
