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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;
        
        ListNode* even = head, *last_even = nullptr;
        ListNode* odd = head->next, *first_odd = head->next;
        
        while(odd || even){
            if(even && even->next && even->next->next){
                even->next = even->next->next;
                even = even->next;
                odd->next = even->next;
                odd = odd->next;
            }
            else{
                last_even = even;
                even = odd = nullptr;
            }
        }

        if(last_even){
            last_even->next = first_odd;
        }
        
        return head;
    }
};