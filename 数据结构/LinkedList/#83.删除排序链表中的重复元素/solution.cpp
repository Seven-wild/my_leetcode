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
       if (head == NULL) return head;
       ListNode *current_node = head, *next_node;
       int pre = head->val;
       while (current_node->next) {
           next_node = current_node->next;
           if (next_node->val == pre) {
               current_node->next = next_node->next;
               delete next_node;
           } else {
               pre = next_node->val;
               current_node = current_node->next;
           }
       }
       return head;
        
    }
};
