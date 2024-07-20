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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* xx;
        if (!list1 && !list2){return xx;}
        else if (!list1 && list2){xx=list2;list2=list2->next;}
        else if (list1 && !list2){xx=list1 ;list1=list1->next;}
        else if (list1->val>list2->val){
            xx=list2;
            list2=list2->next;
        }
        else{xx=list1;list1=list1->next;}
        ListNode* ans=xx;
        while(list1 && list2){
            if (list1->val<list2->val){ans->next=list1;list1=list1->next;ans=ans->next;}
            else{ans->next=list2;list2=list2->next;ans=ans->next;}
        }
        while(list1){ans->next=list1;list1=list1->next;ans=ans->next;}
        while(list2){ans->next=list2;list2=list2->next;ans=ans->next;}
        return xx;


    }
};
