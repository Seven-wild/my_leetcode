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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2;
        //虚拟头节点
        ListNode *prehead = new ListNode();
        ListNode *curr = prehead;
        //进位
        int carry = 0;
        while (p || q) {
            int sum = 0;
            if (p) sum += p->val, p = p->next;
            if (q) sum += q->val, q = q->next;
            sum += carry;
            carry = sum / 10;
            sum %= 10;
            curr->next = new ListNode(sum); 
            curr = curr->next;
        }
        //循环结束进位不为0
        if (carry) {
            curr->next = new ListNode(carry);
        }
        return prehead->next;
    }
};
