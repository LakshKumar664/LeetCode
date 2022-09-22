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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        
        ListNode* head = nullptr;
        ListNode* temp = head;
        
        while(temp1 != nullptr && temp2 != nullptr){
            int data;
            if(temp1->val <= temp2->val){
                data = temp1->val;
                temp1 = temp1->next;
            }
            else{
                data = temp2->val;
                temp2 = temp2->next;                
            }
            
            ListNode* newNode = new ListNode(data);
            if(head == nullptr){
                head = newNode;
                temp = head;
            }            
            else{
                temp->next = newNode;
                temp = temp->next;
            }
        }
        
        while(temp1 != nullptr){
            if(head == nullptr){
                head = new ListNode(temp1->val);
                temp = head;
            } 
            else{
                temp->next = new ListNode(temp1->val);
                temp = temp->next;
            }
            temp1 = temp1->next;
        }
        
        while(temp2 != nullptr){
            if(head == nullptr){
                head = new ListNode(temp2->val);
                temp = head;
            } 
            else{
                temp->next = new ListNode(temp2->val);
                temp = temp->next;
            }
            temp2 = temp2->next;
        }
        
        return head;
    }
};