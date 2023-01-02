/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ptrNext = head;

        ListNode sentinel(0, head);
        ListNode* ptrSentinel = &sentinel;
        
        while(ptrNext){
            if(ptrNext->val != val){
                ptrNext = ptrNext->next;
                ptrSentinel = ptrSentinel->next;
            } else {
                ptrNext = ptrNext->next;
                while(ptrNext && ptrNext->val == val){
                    ptrNext = ptrNext->next;
                }
                ptrSentinel->next = ptrNext;
            }
        }

        return sentinel.next;
    }
};