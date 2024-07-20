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
    ListNode* reverseList(ListNode* head) {
        ListNode* tt;
        if (!head || !head->next){return head;}
        tt=head->next;
        ListNode* str=head;
        while(tt!=NULL){
            ListNode* temp=tt->next;
            tt->next=head;
            head=tt;
            tt=temp;
        }
        str->next=NULL;
        return head;
        
    }
};
