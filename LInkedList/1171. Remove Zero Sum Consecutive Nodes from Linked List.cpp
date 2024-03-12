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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int sm=0;
        unordered_map<int,ListNode*>mp;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        mp[sm]=dummy;

        while(head){
            sm+=head->val;
            if(mp.find(sm)!=mp.end()){
                ListNode*p=mp[sm];
                ListNode*start=p;
                int psum=sm;
                while(start!=head){
                    start=start->next;
                    psum+=start->val;
                    if(start!=head){
                        mp.erase(psum);
                    }
                }
                p->next=start->next;
            }else{
                mp[sm]=head;
            }

            head=head->next;
        }

        return dummy->next;

    }
};