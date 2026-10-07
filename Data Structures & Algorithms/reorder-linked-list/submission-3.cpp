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
 ListNode* reverse(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;

       ListNode* prev = nullptr;
       while(head)
       {
        auto tmp = head->next;
        head->next=prev;
        prev=head;
        head=tmp;
       }
       return prev;
    }
    void reorderList(ListNode* head) {
        if(!head) return;
        if(!head->next) return;

        auto slow = head;
        auto fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        

        auto end = reverse(slow->next);
        slow->next=nullptr;
        auto first = head;
        auto second = end;
        auto tmp = head;
        while(second)
        {
           auto t1 = first-> next;
           auto t2 = second->next;
           first->next = second;
           second->next = t1;
           first = t1;
           second = t2;
        }

        // if(head)
        // {
        //     first->next = head;
        // }
        // head=tmp;
        return ;


    }
};
