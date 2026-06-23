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
        ListNode* curr=head;
        int c=0;
        while(curr!=NULL){
            c++;
            curr=curr->next;
        }
        if(c==n){
            return head->next;
        }
        curr=head;
        int i=0;
        while(i<(c-n-1)){
            curr=curr->next;
            i++;
        }
        curr->next=curr->next->next;
        return head;
    }
};
