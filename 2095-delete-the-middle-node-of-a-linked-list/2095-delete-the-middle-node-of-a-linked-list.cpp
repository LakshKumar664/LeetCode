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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* single_ptr = head;
        ListNode* double_ptr = head;
        ListNode* prev = nullptr;
        
        while(single_ptr && double_ptr && double_ptr->next){            
            prev = single_ptr;
            single_ptr = single_ptr->next;
            double_ptr = double_ptr->next->next;
        }
        
        if(single_ptr && prev)
        prev->next = single_ptr->next;
        
        if(head == single_ptr){
            head = nullptr;
        }
        return head;
    }
};