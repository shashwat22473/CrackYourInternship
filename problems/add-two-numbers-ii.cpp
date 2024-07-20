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
    ListNode* reverse(ListNode *l1){
        ListNode* ptr=new ListNode();
        ListNode* prev=new ListNode();
        prev=nullptr;
        ptr=l1;
        while(ptr){
            ListNode* xx=new ListNode();
            xx=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=xx;
        }
        return prev;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Newl1=reverse(l1);
        ListNode* Newl2=reverse(l2);
        int remainder=0;
        ListNode* ans=new ListNode();

        ans->val=Newl1->val+Newl2->val+remainder;
        remainder=ans->val/10;
        ans->val%=10;
        Newl1=Newl1->next;
        Newl2=Newl2->next;
        ListNode* bitches=ans;
        while(Newl1 && Newl2){
            ListNode* xx =new ListNode();
            xx->val=Newl1->val+Newl2->val+remainder;
            remainder=xx->val/10;
            xx->val%=10;
            Newl1=Newl1->next;
            Newl2=Newl2->next;
            ans->next=xx;
            ans=xx;
        }

        while(Newl1){
            ListNode* xx =new ListNode();
            xx->val=Newl1->val+remainder;
            remainder=xx->val/10;
            xx->val%=10;
            Newl1=Newl1->next;
            ans->next=xx;
            ans=xx;
        }
        while(Newl2){
            ListNode* xx =new ListNode();
            xx->val=Newl2->val+remainder;
            remainder=xx->val/10;
            xx->val%=10;
            Newl2=Newl2->next;
            ans->next=xx;
            ans=xx;
        }
        if (remainder>0){
            ListNode* xx =new ListNode();
            xx->val=remainder;
            remainder=xx->val/10;
            xx->val%=10;
            ans->next=xx;
            ans=xx;
        }
        ListNode* aggin=reverse(bitches);
        return aggin;
    }
};
