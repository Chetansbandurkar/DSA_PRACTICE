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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* node=new ListNode(0);
        ListNode*main=node;
        int sum=0;
        bool found=0;

        ListNode* tmp=head;

        while(tmp){
            if(tmp->val==0 && !found)
            {
                found=1;
                sum+=tmp->val;
            }else if(tmp->val==0 && found){
                ListNode* t=new ListNode(sum);
                node->next=t;
                node=t;
                sum=0;
            }
            else sum+=tmp->val;

            tmp=tmp->next;
        }

        return main->next;
    }
};