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
    ListNode* reverse(ListNode* head,ListNode* end)
    {
        ListNode* prev=nullptr;
        auto back = head;
        while(head!=end)
        {
            auto tmp = head->next;
            head->next=prev;
            prev=head;
            head=tmp;
        }
        back->next=end;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
       
        ListNode* tmp = &dummy;
        
        bool flag=false;
        ListNode* combiner;
        while(head)
        {
            int i=0;
            auto end = head;
            while(i<k && end)
            {
                end=end->next;
                i++;
            }
            if(i==k)
            {
                auto newHead=reverse(head,end);
                tmp->next=newHead;
                tmp=head;
                head=end;
            }
            else break;
        }
        return dummy.next;

    }
};
