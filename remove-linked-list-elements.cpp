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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val==val){
            head=head->next;
        }
        ListNode* ans=head;
        ListNode* prev=head;
        if (!head){return head;}
        head=head->next;
        while(head){
            if (head->val==val){prev->next=head->next;head=head->next;}
            else{
                prev=head;
                head=head->next;
            }

        }
        return ans;
    }
};
