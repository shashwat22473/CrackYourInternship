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
    bool hasCycle(ListNode *head) {
        ListNode* xx=head;
        while(xx && xx->next){
            head=head->next;
            xx=xx->next->next;
            if (head==xx){return true;}
        }
        return false;
        
    }
};
