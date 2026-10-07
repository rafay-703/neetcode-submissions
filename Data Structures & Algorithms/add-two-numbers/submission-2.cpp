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
    ListNode* reverse(ListNode* head)
    {
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverse(l1);
        // l2 = reverse(l2);
        // auto first=l1,second=l2;
        auto ans = l1;
        bool carry = false;
        auto num = l1->val+l2->val;
        l1->val = num%10 + carry;
        if(num>=10) carry=true;
            
        while(l1->next && l2->next)
        {
            l1=l1->next;
            l2=l2->next;
        
            auto num = l1->val+l2->val+carry;
            l1->val = num%10;
            if(num>=10) carry=true;
            else carry=false;
        }
        // 1234
        // 432
        // 4321+234 = 
        auto tmp = l1->next;
        if(l2->next)
        {
            l1->next=l2->next;
        }
        while(l1->next)
        {
            l1=l1->next;
            auto num = l1->val+carry;
            l1->val = num%10;
            if(num>=10) carry=true;
            else carry=false;
            if(!carry) break;
        }
        // auto ans= reverse(first);
        if(carry)
        {
            auto copy=ans;
            while(copy->next) copy=copy->next;
            copy->next=new ListNode(1);
        }
        return ans;
    }
};
