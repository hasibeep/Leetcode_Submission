/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       if(head==NULL || head->next==NULL){
        return NULL;
       }
       unordered_map<ListNode*,int>mp;
       ListNode* temp=head;
       while(temp!=NULL){
        mp[temp]++;
        temp=temp->next;
        if(mp[temp]>1){
            return true;
        }
       }
      return false;
    }
};