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
    ListNode* partition(ListNode* head, int x) {if(head==NULL) return head;
        vector<int>smaller;
        vector<int>greater;
        ListNode* curr=NULL;
        curr= head;
        while(curr){
            if(curr->val>=x) greater.push_back(curr->val);
            else smaller.push_back(curr->val);
            curr= curr->next;
        }
        for(int i=0;i<greater.size();i++){
            smaller.push_back(greater[i]);
        }
        ListNode* ans;
        ListNode* temp= new ListNode(smaller[0]);ans = temp;
      for(int i=1;i<smaller.size();i++){
            temp->next= new ListNode(smaller[i]);
            temp = temp->next;
            
        }
        return ans;

        
    }
};