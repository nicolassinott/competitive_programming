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
    bool hasCycle(ListNode *head) {
        ListNode sentinelNode(0);
        sentinelNode.next = head;
        ListNode* ptrTurtle = &sentinelNode;

        while(head){
            if(head == ptrTurtle)
                return 1;

            head = head->next;
            if(head)
                head = head->next;
            else
                break;
            ptrTurtle = ptrTurtle->next;
        }
        return 0;

    }
};