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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* mergedList = nullptr;
        ListNode* temp = head->next;
        ListNode* temp1 = nullptr;
        
        int sum = 0;

        while(temp != nullptr){
            if(temp->val == 0){
                ListNode* newNode = new ListNode(sum);
                sum = 0;
                
                if(!mergedList){
                    temp1 = newNode;
                    mergedList = newNode;
                }
                else{
                    temp1->next = newNode;
                    temp1 = newNode;
                }
            }
            else{
                sum += temp->val;
            }
            
            temp = temp->next;
        }
        
        return mergedList;
    }
};