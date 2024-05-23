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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode*cur=head;
        while(cur){
            st.push(cur);
            cur=cur->next;
        }

        ListNode*resHead=new ListNode(st.top()->val);
        int mx=st.top()->val;
        st.pop();
        while(!st.empty()){
            ListNode*curr=st.top();
            st.pop();
            if(curr->val<mx){
                continue;
            }
            else{
                ListNode*nextNode=new ListNode(curr->val);
                nextNode->next=resHead;
                resHead=nextNode;
                mx=curr->val;
            }
        }

        return resHead;
        
    }
};