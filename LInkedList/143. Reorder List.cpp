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
    ListNode* reverseL(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        // first find the  mid;
        if (head->next == NULL)
            return;
        ListNode *slow = head, *fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // MId ko null karna mat bhul bhai 
        // 
        ListNode* reverse = reverseL(slow->next);
        slow->next = NULL;
        while (reverse) {
            ListNode* headNext = head->next;
            head->next = reverse;
            ListNode* reverseNext = reverse->next;
            reverse->next = headNext;
            head = headNext;
            reverse = reverseNext;
        }
    }
};