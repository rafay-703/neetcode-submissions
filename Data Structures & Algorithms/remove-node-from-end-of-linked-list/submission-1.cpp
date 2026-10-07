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
        auto fast=head,slow=head;
        
        while(n-->0 && fast)
            fast=fast->next;
        if(!fast) return head->next;
        while(fast && fast->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
        if(!slow->next){
            return nullptr;
        }
        auto tmp = slow->next;
        slow->next=slow->next->next;
        delete tmp;
        return head;
    }
};
