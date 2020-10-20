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
    ListNode* swapPairs(ListNode* head) {
        ListNode *prehead = new ListNode(-1,head);
        ListNode *current = prehead;
        ListNode *first, *second;
        while (current->next != nullptr && current->next->next != nullptr) {
            first = current->next;
            second = first->next;
            current->next = second;
            first->next = second->next;
            second->next = first;
            current = first;
        }
        return prehead->next;
    }
};
