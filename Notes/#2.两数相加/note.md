2. 两数相加

难度中等5359

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807



思路：

先创建一个虚拟头结点prehead,然后每次创建一个新的结点加到链表尾部，其值为当前遍历到的两个链表结点之和加上进位，要注意如果两个链表都遍历结束后如果还有进位应再加一个结点。



代码：

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
            ListNode *prehead = new ListNode();
            ListNode *current = prehead;
            ListNode *p = l1, *q = l2;
            int carry = 0;
            while (p || q) {
                int sum = 0;
                if (p) {
                    sum += p->val;
                    p = p->next;
                }
                if (q) {
                    sum += q->val;
                    q = q->next;
                }
                sum += carry;
                carry = sum / 10;
                sum %= 10;
                current->next = new ListNode(sum);
                current = current->next;
            } 
            if (carry) {
                current->next = new ListNode(carry);
            }
            return prehead->next;
        }
    };


