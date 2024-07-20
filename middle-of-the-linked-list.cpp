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
    ListNode* middleNode(ListNode* head) {
        int count_=1;
        ListNode* xx=head;
        while(head->next!=NULL){
            count_++;
            head=head->next;
        }
        count_=count_/2;
        while(count_>0){
            xx=xx->next;
            count_--;
        }
        return xx;
        
    }
};
