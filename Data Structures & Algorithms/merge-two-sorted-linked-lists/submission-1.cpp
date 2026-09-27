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
        if(!list1 && !list2) return list1;
        auto ans = new ListNode();
        auto head = ans;
        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                ans->val=list1->val;
                ans->next= new ListNode();
                list1=list1->next;
                ans = ans-> next;
            }
            else
            {
                ans->val=list2->val;
                ans->next= new ListNode();
                list2 = list2->next;
                ans = ans->next;
            }
        }
        while(list1)
        {    
            ans->val=list1->val;
            if(list1->next)
                ans->next= new ListNode();
            list1=list1->next;
            ans = ans-> next;
        }   
        while(list2)
        {
            ans->val=list2->val;
            if(list2->next)
                ans->next= new ListNode();
            list2 = list2->next;
            ans = ans->next;
        }

    return head;
    }
};
