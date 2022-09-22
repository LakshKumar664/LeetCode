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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        
        while(temp && temp->next){
            ListNode* next = temp->next->next;
            // temp->next = temp;
            if(temp == head){
                head =  temp->next;
            }
            else{
                prev->next = temp->next;
            }
            
            temp->next->next = temp;
            temp->next = next;
            prev = temp;
            temp = temp->next;
        }
        
        return head;
    }
};