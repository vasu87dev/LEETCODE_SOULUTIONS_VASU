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



if (head == NULL || head->next == NULL || head->next->next == NULL)
{
    return {-1,-1};
}
        ListNode* previous=head;
        ListNode* current=head->next;
         ListNode* nest=current->next;


        int pos = 1;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;


         while(nest)
         {
            if((previous->val<current->val && current->val>nest->val)|| (previous->val>current->val && current->val<nest->val))
            {
                 if(first==-1)
                 {
                    first=pos;
                 }
                 else
                 {
                    minDist=min(minDist,pos-last);
                 }
                 last=pos;
            }
         
            
            pos++;
            previous=current;
            current=nest;
            nest=nest->next;
         }


     if (first == last)
            return {-1, -1};





        return {minDist, last - first};
         }
        
    
};