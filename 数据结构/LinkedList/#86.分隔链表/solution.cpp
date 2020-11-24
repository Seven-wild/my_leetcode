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
    ListNode* partition(ListNode* head, int x) {
        ListNode *prehead = new ListNode(-1);
        prehead->next = head;
        ListNode *current = prehead;
        while (current && current->next) {
            while (current->next && current->next->val < x) current = current->next;
            if (!current->next) break;
            ListNode *change = current->next;
            while (change->next && change->next->val >= x) change = change->next;
            if (!change->next) break;
            ListNode *temp = change->next;
            change->next = change->next->next;
            temp->next = current->next;
            current->next = temp;
            current = current->next;
        }
        return prehead->next;

    }
};
