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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prehead = new ListNode(-1);
        prehead->next = head;
        ListNode *current_node = prehead;
        while (current_node->next && current_node->next->next) {
            ListNode *next_node = current_node->next;
            if (next_node->next && next_node->val != next_node->next->val) {
                current_node = next_node;
                continue;
            }
            while (next_node->next && next_node->next->val == next_node->val) {
                next_node = next_node->next;
            }
            current_node->next = next_node->next;

        }
        return prehead->next;
    }
};
