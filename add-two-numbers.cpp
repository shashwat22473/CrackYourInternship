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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode();
        ListNode* prev=ans;
        
        int remainder=0;
        prev->val=l1->val +l2->val+remainder;
        remainder=prev->val/10;
        prev->val=prev->val%10;
        l1=l1->next;
        l2=l2->next;
        while(l1 && l2){
            ListNode* xx=new ListNode();
            xx->val=l1->val +l2->val+remainder;
            remainder=xx->val/10;
            xx->val=xx->val%10;
            prev->next=xx;
            prev=xx;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            ListNode* xx=new ListNode();
            xx->val=l1->val+remainder;
            remainder=xx->val/10;
            xx->val=xx->val%10;
            prev->next=xx;
            prev=xx;
            l1=l1->next;
        }
        while(l2){
            ListNode* xx=new ListNode();
            xx->val=l2->val+remainder;
            remainder=xx->val/10;
            xx->val=xx->val%10;
            prev->next=xx;
            prev=xx;
            l2=l2->next;
        }
        if (remainder>0){
            ListNode* xx=new ListNode();
            xx->val=remainder;
            prev->next=xx;
        }
        return ans;
    }
};
