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
    int getDecimalValue(ListNode* head) {
        ListNode* xx=head;
        int count_=0;
        while(xx){
            count_++;
            xx=xx->next;
        }
        int ans=0;
        while(head){
            count_--;
            if (head->val==1){
                ans+=(1<<count_);
            }
            head=head->next;
        }
        return ans;
    }
};
