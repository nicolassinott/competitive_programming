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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode sentinel(0);
        ListNode* ptrSentinel = &sentinel;
        while(list1 || list2){
            if(!list1){
                ptrSentinel->next = list2;
                list2 = list2->next;
                ptrSentinel = ptrSentinel->next;
            } else if (!list2){
                ptrSentinel->next = list1;
                list1 = list1->next;
                ptrSentinel = ptrSentinel->next;
            } else {
                if(list1->val < list2->val){
                    ptrSentinel->next = list1;
                    ptrSentinel = ptrSentinel->next;
                    list1 = list1->next;
                } else {
                    ptrSentinel->next = list2;
                    ptrSentinel = ptrSentinel->next;
                    list2 = list2->next;
                }
            }
        }

        return sentinel.next;
    }
};