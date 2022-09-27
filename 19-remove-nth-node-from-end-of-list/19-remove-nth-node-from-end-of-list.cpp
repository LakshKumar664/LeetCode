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
        int count = 1;
        int total_nodes = 0;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        
        while(temp){
            total_nodes ++;
            temp = temp->next;
        }
        
        int nth_node = total_nodes - n + 1;
        temp = head;
        
        while(temp && count <= nth_node){
            
            if(count == nth_node){
                if(temp == head){
                    head = temp->next;                            
                }                
                else{
                    prev->next = temp->next;
                    
                }
            }
            
            count ++;
            prev = temp;
            temp = temp->next;
        }
        
        return head;
    }
};