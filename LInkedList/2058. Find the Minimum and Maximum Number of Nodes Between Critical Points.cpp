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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next) return {-1,-1};

        ListNode*tmp=head->next;
        ListNode*prev=head;
        int fst=-1;
        int cnt=1;
        int lst=-1;
        int ppre=-1;
        int mn=INT_MAX;
        int mx=INT_MIN;
        while( tmp->next){
            // cnt++;

            if(tmp->val>prev->val && tmp->val>tmp->next->val){
                if(fst==-1){
                    fst=cnt;
                    ppre=cnt;
                    lst=cnt;
                }
                else {
                    mn=min(mn,cnt-ppre);
                    ppre=cnt;
                    lst=cnt;
                }
            }
            if(tmp->val<prev->val && tmp->val<tmp->next->val){
                if(fst==-1){
                    fst=cnt;
                    ppre=cnt;
                    lst=cnt;
                }
                else {
                    mn=min(mn,cnt-ppre);
                    ppre=cnt;
                    lst=cnt;
                }
            }
            prev=tmp;
            tmp=tmp->next;
            cnt++;

        }

        if(mn==INT_MAX) return {-1,-1};

        return {mn,lst-fst};
    }
};