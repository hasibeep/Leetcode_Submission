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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* temp=head->next;
        int pos=1;
        int min_dis=INT_MAX;
        int max_dis=0;

        vector<int>ans={-1,-1};
        int firstcritical=-1;
        int prevcritical=0;
        
        if(head->next==nullptr || head->next->next==nullptr){
            return ans;
        }

        while(temp->next!=nullptr){
            if((temp->val>prev->val && temp->val>temp->next->val)|| 
                (temp->val <prev->val && temp->val<temp->next->val) ){
                    if(firstcritical==-1){
                        firstcritical=pos;
                    }
                    else {
                        min_dis=min(min_dis,pos-prevcritical);
                        max_dis=max(max_dis,pos-firstcritical);
                    }
                    prevcritical=pos;
                }
                prev=temp;
                temp=temp->next;
                pos++;
        }
        if(min_dis==INT_MAX){
            return {-1,-1};
        }
        ans={min_dis,max_dis};
        return ans;
    }
};