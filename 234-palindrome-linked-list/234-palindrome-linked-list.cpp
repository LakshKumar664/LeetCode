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
    bool isPalindrome(ListNode* head) {
        
        /*
            SOLUTION IN ONE PASS
            Time: O(N)  
            Space: O(1)
        */
        
        bool is_palindrome = true;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        
        traverse(temp1, temp2, is_palindrome);
        
        return is_palindrome;
    }
    
    ListNode* traverse(ListNode* temp1, ListNode* temp2, bool& is_palindrome){
        if(!temp2)
            return nullptr;
        ListNode* n = nullptr;
        
        if(temp2->next){
            n = traverse(temp1, temp2->next, is_palindrome);
        }
        else{
            n = temp1;
        }
        
        if(n->val != temp2->val){
            is_palindrome = false;
        }
        
        return n->next;
    }
};