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
    // 翻转k个节点
    pair<ListNode *, ListNode *> myReverse(ListNode *head, ListNode *last) {
        ListNode *prev = last->next, *curr = head;
        while (prev != last) {
            ListNode *nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return {last, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 虚拟头节点
        ListNode *prehead = new ListNode(0, head);
        // hair tail是需要翻转的k个节点的前一个和后一个节点
        // last 是需要翻转的k个节点的最后一个节点
        ListNode *hair = prehead, * tail, *last;
        while (head) {
            last = hair;
            for (int i = 0; i < k; i++) {
                last = last->next;
                //如果剩余节点不足k个 直接返回
                if (!last) return prehead->next;
            }
            tail = last->next;
            auto temp = myReverse(head, last);
            head = temp.first;
            last = temp.second;
            hair->next = head;
            last->next = tail;
            hair = last;
            head = hair->next;
        }
        return prehead->next;
    }
};
