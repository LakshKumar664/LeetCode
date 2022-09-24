/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> intersection;
        ListNode* temp = headA;
        ListNode* intersect_node = NULL;
        
        while(temp){
            intersection[temp] = 1;
            temp = temp->next;
        }
        
        temp = headB;
        
        while(temp){
            if(intersection.count(temp)){
                intersect_node = temp;
                break;
            }
            temp = temp->next;
        }
        
        return intersect_node;
    }
};