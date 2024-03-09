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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        for(int i = 1; i <= n; i++) {
            fast = fast->next;
        }
        if(fast == NULL) {
            return head->next;
        }
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);
        return head;
        // ListNode* tmp = head;
        // int cnt = 0;
        // while (tmp) {
        //     tmp = tmp->next;
        //     cnt++;
        // }
        // // if (cnt == 1 && n == 1)
        // //     return NULL;
        // // cnt = cnt - n;/
        // if(cnt==n){
        //     ListNode*t=head->next;
        //     delete(head);
        //     return t;
        // }
        // int trav=cnt-n;
        // tmp = head;
        // ListNode* prev = NULL;
        // while(trav--){
        //     prev=tmp;
        //     tmp=tmp->next;
        // }
        // prev->next=tmp->next;
        // delete(tmp);
        // return head;

    }
};