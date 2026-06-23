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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            //2nd middle 
            //if 1st middle initialize ListNode* fast=head->next;
        }
        ListNode* second=slow->next;
        slow->next=NULL;

        ListNode* prev=NULL;
        ListNode* forward=NULL;
        while(second!=NULL){
            forward=second->next;
            second->next=prev;
            prev=second;
            second=forward;
        }

        ListNode* first=head;
        second=prev;

        while(first!=NULL && second!=NULL){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
        return;

    }
};
