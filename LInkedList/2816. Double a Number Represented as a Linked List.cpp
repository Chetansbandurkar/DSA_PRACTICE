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
    ListNode* doubleIt(ListNode* head) {
        ListNode*resH=NULL;
        while(head){
            ListNode*cur=head;
            cur=head->next;
            head->next=resH;
            resH=head;
            head=cur;
        }   
        // return resH;
        int prev=0;
        ListNode*resHH=NULL;
        while(resH){
            int k=resH->val;
            k=k*2+prev;
            prev=k/10;
            resH->val=k%10;
            ListNode*c=resH->next;
            resH->next=resHH;
            resHH=resH;
            resH=c;
        }
        if(prev>0){
            ListNode*n=new ListNode(prev);
            n->next=resHH;
            resHH=n;
        }
        return resHH;
    }
};