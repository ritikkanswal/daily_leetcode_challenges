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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *fast=head->next;
        ListNode *slow=head;
        slow->next=NULL;
        while(fast !=NULL)
        {
            ListNode * tmp;
            tmp = fast-> next;
            fast ->next = slow;
            slow = fast;
            fast = tmp;
        }
        return slow;
    }
};