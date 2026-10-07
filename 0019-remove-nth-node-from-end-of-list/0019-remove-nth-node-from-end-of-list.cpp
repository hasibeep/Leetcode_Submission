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
        if(head==NULL){
            return NULL;
        }
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if (n == cnt) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int x=cnt-n;
        temp=head;
        ListNode* prev=NULL;
        int i=0;
        while(i<x){
            
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        temp->next=NULL;
        delete temp;
        return head;
    }
};