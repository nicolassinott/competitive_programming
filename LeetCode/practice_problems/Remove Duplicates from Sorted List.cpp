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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* ptrHead = head;
        ListNode* ptrNext = head;

        while(ptrNext){
            while(ptrNext && ptrNext->val == ptrHead->val){
                ptrNext = ptrNext->next;
            }
            ptrHead->next = ptrNext;
            ptrHead = ptrNext;
        }

        return head;
    }
};