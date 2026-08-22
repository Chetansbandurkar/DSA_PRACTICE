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
        ListNode* a = l1;
        ListNode* b = l2;

        ListNode* ans = new ListNode(0);
        ListNode* trav = ans;
        int rem = 0;

        while (a && b) {
            int add = a->val + b->val + rem;
            rem = add / 10;
            int val = add % 10;

            ListNode* tmp = new ListNode(val);
            trav->next = tmp;
            trav = trav->next;
            a = a->next;
            b = b->next;
        }

        while (a) {
            int add = a->val + rem;
            rem = add / 10;
            int val = add % 10;

            ListNode* tmp = new ListNode(val);
            trav->next = tmp;
            trav = trav->next;
            a = a->next;
        }

        while (b) {
            int add = b->val + rem;
            rem = add / 10;
            int val = add % 10;

            ListNode* tmp = new ListNode(val);
            trav->next = tmp;
            trav = trav->next;
            b = b->next;
        }

        while (rem) {
            int add = rem;
            rem = add / 10;
            int val = add % 10;

            ListNode* tmp = new ListNode(val);
            trav->next = tmp;
            trav = trav->next;
        }

        return ans->next;
    }
};