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
            
        vector<int> array;
        
        ListNode* curr = head;
        while(curr != nullptr)
        {
            array.push_back(curr->val);
            curr = curr->next;
        }
        
  
        
        for(int i = 1; i < array.size(); i++)
        {
            int j = i;
            while(array[j] < array[j - 1] && j > 0)
            {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                
                j--;
            }

        }
        
        
        ListNode* ccurr = head;
        
        for(auto i: array)
        {
            ccurr->val = i;
            ccurr = ccurr->next;
        }
    
        
        return head;
    }
};
