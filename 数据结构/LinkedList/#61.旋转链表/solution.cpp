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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        ListNode *current = head, *tail;
        int length = 1;
        while (current->next != NULL) {
            length++;
            current = current->next;
        }
        k %= length;
        if(k == 0) return head;
        current->next = head;
        int n = length - k;
        while (n--) {
            current = current->next;
        } 
        head = current->next;
        current->next = NULL;
        return head;

    }
};
