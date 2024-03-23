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
   ListNode*reverse(ListNode*head){
    ListNode*cur=head;
    ListNode*prev=NULL;
    ListNode*next=NULL;
    while(cur){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
   }
    bool isPalindrome(ListNode* head) {
         // find the mid value make it reverse
        //   then check fromt head and reverse value if not equal data return
        //   false;
        // get mid 
        if(head->next==NULL)return head;
        ListNode*slow=head,*fast=head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;

        while(slow){
            if(slow->val!=head->val){
                return false;
            }
            slow=slow->next;
            head=head->next;
        }

        return true;
    }
};