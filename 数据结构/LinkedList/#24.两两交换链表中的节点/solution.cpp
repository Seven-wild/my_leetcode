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
        // 虚拟头节点
        ListNode *prehead = new ListNode(0, head);
        // 需要交换的两个节点的前一个节点
        ListNode *hair = prehead;
        // 交换的第一个节点和第二个节点
        ListNode *first, *second;
        while (hair->next && hair->next->next) {
            first = hair->next;
            second = first->next;
            hair->next = second;
            first->next = second->next;
            second->next = first;
            hair = first;
        }
        return prehead->next;
    }
};
