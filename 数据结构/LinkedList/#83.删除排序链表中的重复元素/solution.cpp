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
       ListNode *current_node = head;
       while (current_node->next) {
           if (current_node->val == current_node->next->val) 
                current_node->next = current_node->next->next;
           else
                current_node = current_node->next;
       }
       return head;
    }
};
