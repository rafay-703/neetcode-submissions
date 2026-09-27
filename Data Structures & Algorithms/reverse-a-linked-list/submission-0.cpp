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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        auto prev = head;
        auto curr = head->next;
        prev->next=nullptr;
        while(curr)
        {
            auto tmp = curr->next;
            
            curr->next=prev;
            prev=curr;
            if(!tmp) break;
            curr = tmp;
        }
        return curr;
    }
};
