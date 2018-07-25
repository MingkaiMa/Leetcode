/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int start_value = (l1->val + l2->val) % 10;
        
        int carry = (l1->val + l2->val) / 10;
        
        ListNode* start = new ListNode(start_value);
        ListNode* curr = start;
       
        
        while(1){

            if(l1->next != NULL && l2->next != NULL){
            
                l1 = l1->next;
                l2 = l2->next;
                        
                int put_value = (l1->val + l2->val + carry) % 10;
                carry = (l1->val + l2->val + carry) / 10;
                
                ListNode* next = new ListNode(put_value);
                curr->next = next;
                curr = next;
                
            }
            else if(l1->next && l2->next == NULL){
                
                l1 = l1->next;
                int put_value = (l1->val + 0 + carry) % 10;
                carry = (l1->val + 0 + carry) / 10;
                ListNode* next = new ListNode(put_value);
                curr->next = next;
                curr = next;                
            }
            
            else if(l1->next == NULL && l2->next){
                
                
                l2 = l2->next;
                int put_value = (l2->val + 0 + carry) % 10;
                carry = (l2->val + 0 + carry) / 10;
                ListNode* next = new ListNode(put_value);
                curr->next = next;
                curr = next; 
            }
            
            else if(l1->next == NULL & l2->next == NULL){

                if(carry != 0){
                    int put_value = carry;
                    ListNode* next = new ListNode(put_value);
                    curr->next = next;
                    curr = next; 
                }
                break;
                
            }
            
            
        }
        
        return start;
    }
};
