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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        
        
        
        int lenA = 0;
        ListNode* currA = headA;
        while(currA != nullptr)
        {
            lenA++;
            currA = currA->next;
        }
        
        int lenB = 0;
        ListNode* currB = headB;
        while(currB != nullptr)
        {
            lenB++;
            currB = currB->next;
        }
        
        if(lenA == lenB)
        {
            currA = headA;
            currB = headB;
        }
        else if(lenA > lenB)
        {
            int diff = lenA - lenB;
            currA = headA;
            while(diff > 0)
            {
                currA = currA->next;
                diff--;
            }
             
            currB = headB;
        }
        else
        {
            int diff = lenB - lenA;
            currB = headB;
            while(diff > 0)
            {
                currB = currB->next;
                diff--;
            }
            currA = headA;
        }        
        while(currA != nullptr && currB != nullptr && currA != currB)
        {
            currA = currA->next;
            currB = currB->next;
        }
        
        if(currA == nullptr)
            return nullptr;
        
        return currA;
        
    }
};
