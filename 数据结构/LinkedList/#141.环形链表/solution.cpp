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
        ListNode *fast = head;
        ListNode *slow = head;
        int cnt = 0;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            cnt++;
            if (slow == fast) break;
        }
        if (fast && fast == slow && cnt > 0) return true;  
        return false;
    }
};
