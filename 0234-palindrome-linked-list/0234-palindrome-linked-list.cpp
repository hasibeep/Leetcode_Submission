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
        if(head==NULL || head->next==NULL) return true;
        ListNode* h=head;
        ListNode* a=head;
        while(a!=NULL && a->next!=NULL){
            h=h->next;
            a=a->next->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=h;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode* left=head;
        ListNode* right=prev;
        while(right!=NULL){
            if(right->val!=left->val){
                return false;
            }
            
            right=right->next;
            left=left->next;
        }
        return true;
    }
};