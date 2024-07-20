/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0;int m=0;
        ListNode* ptr1=headA;
        ListNode* ptr2=headB;

        while(ptr1){ptr1=ptr1->next;n++;}
        while(ptr2){ptr2=ptr2->next;m++;}
        while(n>m){
            headA=headA->next;
            n--;
        }
        while(m>n){
            headB=headB->next;
            m--;
        }
        while(headA && headB){
            if (headA==headB){return headA;}
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};
