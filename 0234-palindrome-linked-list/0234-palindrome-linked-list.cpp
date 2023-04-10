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
        ListNode* slow=head,*fast=head;
        // find middle
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast && fast->next==0){
            slow=slow->next;
        }
        // reverse back half
        ListNode* prev=NULL;
        while(slow && slow->next){
            ListNode* nextNode=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nextNode;
        }
        if(slow)slow->next=prev;
        fast=head;
        // compare first half and back half
        while(slow && fast){
            if(slow->val!=fast->val)return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};