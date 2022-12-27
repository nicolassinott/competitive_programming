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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head->next)
            return nullptr;
        
        int count = 0;
        ListNode* itPtr = head;
        
        ListNode prev(0);
        prev.next = head;
        ListNode* ptrPrev = &prev;

        while(count < n){
            itPtr = itPtr->next;
            count++;
        }

        if(!itPtr){
            return head->next;
        }

        while(itPtr){
            itPtr = itPtr->next;
            ptrPrev = ptrPrev->next;
        }

        if(!ptrPrev->next->next){
            ptrPrev->next = nullptr;
        } else {
            ptrPrev->next = ptrPrev->next->next;
        }

        return head;
    }
};