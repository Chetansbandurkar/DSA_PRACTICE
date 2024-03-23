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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int ind=1;
        ListNode*ptr1=list1;
        while(ind<a){
            ptr1=ptr1->next;
            ind++;
        }
        ListNode*ptr2=ptr1;
        while(ind<=b+1){
            ptr2=ptr2->next;
            ind++;
        }
        ptr1->next=list2;
        while(ptr1->next){
            ptr1=ptr1->next;
        }
        ptr1->next=ptr2;
        return list1;
    }
};