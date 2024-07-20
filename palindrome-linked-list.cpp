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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* ptr=head;
        while(head){
            st.push(head->val);
            head=head->next;
        }
        while(ptr){
            if (ptr->val!=st.top()){
                return false;
            }
            ptr=ptr->next;
            st.pop();
        }
        return true;
    }
};
