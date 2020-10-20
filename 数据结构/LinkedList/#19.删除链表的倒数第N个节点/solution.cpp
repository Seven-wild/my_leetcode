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
        ListNode *prehead = new ListNode(-1,head);
        ListNode *current = prehead, *detect = current->next;
        while (n--) {
            detect = detect->next;
        }
        while (detect != nullptr) {
            current = current->next;
            detect = detect->next;
        }
        current->next = current->next->next;
        return prehead->next;
    }
};
