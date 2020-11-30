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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pre_node = new ListNode(-1);
        pre_node->next = head;
        ListNode *cur_node, *next_node, *last_node, *sub_head, *sub_tail;
        for (int i = 0; i < m - 1; i++) {
            pre_node = pre_node->next;
        }
        sub_head = pre_node->next;
        sub_tail = sub_head;
        cur_node = sub_head->next;
        sub_head->next = NULL;
        for (int i = 0; i < n - m; i++) {
            if (i == n - m - 1) last_node = cur_node->next;
            next_node = cur_node->next;
            cur_node->next = sub_head;
            sub_head = cur_node;
            cur_node = next_node;
        }
        pre_node->next = sub_head;
        sub_tail->next = cur_node;
        if (m == 1) return pre_node->next;
        return head;
    }
};
