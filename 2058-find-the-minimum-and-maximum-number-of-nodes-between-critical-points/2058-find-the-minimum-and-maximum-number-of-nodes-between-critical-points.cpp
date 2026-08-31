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

vector<int>arr;
        vector<int>hash;



if (head == NULL || head->next == NULL || head->next->next == NULL)
{
    return {-1,-1};
}
        ListNode* previous=head;
        ListNode* current=head->next;
         ListNode* nest=current->next;



int count=1;
         while(nest!=NULL)
         {
            if((previous->val<current->val && current->val>nest->val)|| (previous->val>current->val && current->val<nest->val))
            {
                 hash.push_back(count);
            
            }
            count++;
            previous=current;
            current=nest;
            nest=nest->next;
         }
            
if (hash.size() < 2)
            return {-1, -1};

int min1=INT_MAX;
for(int i=1;i<hash.size();i++)
{
min1=min(min1,hash[i]-hash[i-1]);
}
arr.push_back(min1);

int a=hash[hash.size()-1]-hash[0];
arr.push_back(a);

return arr;
         }
        
    
};