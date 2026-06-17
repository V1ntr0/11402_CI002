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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        int n = 0;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }

        int mid = n / 2;

        cur = head;
        for (int i = 1; i < mid; i++) {
            cur = cur->next;
        }

        ListNode* right = cur->next;
        cur->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* t = &dummy;

        while (a && b) {
            if (a->val < b->val) {
                t->next = a;
                a = a->next;
            } else {
                t->next = b;
                b = b->next;
            }
            t = t->next;
        }

        t->next = a ? a : b;
        return dummy.next;
    }
};