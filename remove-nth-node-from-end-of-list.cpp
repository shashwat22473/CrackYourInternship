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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int  count_=0;
        ListNode* ptr=head;
        ListNode* ans=new ListNode();ans=head;
        while(head){count_++;head=head->next;}
        count_-=n;
        if (count_==0){ans=ans->next;return ans;}
        while(count_>1){
            ptr=ptr->next;
            count_--;
        }
        ptr->next=ptr->next->next;
        return ans;
        
    }
};
