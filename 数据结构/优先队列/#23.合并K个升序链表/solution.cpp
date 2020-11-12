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
    struct Node {
        int val;
        ListNode *p;
        friend bool operator < (const Node &a, const Node &b) {
            return a.val > b.val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node> q;
        ListNode *prehead = new ListNode(-1), *current = prehead;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                q.push({lists[i]->val, lists[i]});
        }
        while (!q.empty()) {
            Node temp = q.top();
            q.pop();
            current->next = temp.p;
            current = current->next;
            if (temp.p->next) q.push({temp.p->next->val, temp.p->next}); 
        }
        return prehead->next;
    }
};
