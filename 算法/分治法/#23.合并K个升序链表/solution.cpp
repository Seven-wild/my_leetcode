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
    ListNode *mergeTwoLists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode *prehead = new ListNode(-1), *current = prehead, *pa = a, *pb = b;
        while (pa && pb) {
            if (pa->val > pb->val) {
                current->next = pb;
                pb = pb->next;
            } else {
                current->next = pa;
                pa = pa->next;
            }
            current = current->next;
        }
        current->next = (pa ? pa : pb);
        return prehead->next;
    }
    ListNode *merger(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merger(lists, l, mid), merger(lists, mid + 1, r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         return merger(lists, 0 , lists.size() - 1);
    }
};
