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
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(cnt==n){
            temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        temp=head;
        ListNode* prev=NULL;
        while(cnt>n){
            
            cnt--;
            prev=temp;
            temp=temp->next;
            
        }
        prev->next=temp->next;
        temp->next=NULL;
        delete temp;
        return head;
    }
};