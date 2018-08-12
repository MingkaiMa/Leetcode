/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

        if(head == nullptr)
            return nullptr;
        
        unordered_map<RandomListNode*, RandomListNode*> hashMap;
        
        RandomListNode* newHead = new RandomListNode(head->label);
        hashMap[newHead] = head->random;
        
        RandomListNode* curr = head->next;
        
        RandomListNode* preNode = newHead;
        
        while(curr)
        {
            RandomListNode* newNode = new RandomListNode(curr->label);
            hashMap[newNode] = curr->random;
            preNode->next = newNode;
            preNode = newNode;
            curr = curr->next;
        }
        
        
        curr = newHead;
        
        while(curr)
        {
            RandomListNode* preRandom = hashMap[curr];
            
            
            if(preRandom == nullptr)
            {
               RandomListNode* newRandom = nullptr; 
               curr->random = newRandom;
               curr = curr->next;
            }
            else{
                
                RandomListNode* newRandom = new RandomListNode(preRandom->label);
                curr->random = newRandom;
                curr = curr->next;
            }
        }
        return newHead;
    }
};
